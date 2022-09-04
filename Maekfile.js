//Run this (javascript) file with node:
//$ node Maekfile.js [-jN] [-v] [-q] [--] [target1] [target2] [...]
//
// Maekfile.js will [re-]build all the specified targets.
// Results are re-used by content hash if they match "maek-cache.json"; delete that file to force a full rebuild.
//
//Command line options:
//  -jN      limit on parallel jobs; defaults to number of cpu cores + 1
//  -v       verbose output; prints more info
//  -q       quit on first error
//  --       optional separator between command line switches and targets (useful if you have a target named '-j1')
//  targetN  target name. Posix-style path to a file to build, or an abstract target (word starting with ':')
//

//maek is configured using properties and methods of the `maek` object:
const maek = init_maek();
// (it's a quirk of javascript that function definitions anywhere in scope get 'hoisted'
//   -- you can see the definition of init_maek by scrolling down.)

//-------------------------------------------------------------------
//Read onward to discover how to configure Maek for your build!

const NEST_LIBS = `../nest-libs/${maek.OS}`;

//set compile flags (these can also be overridden per-task using the "options" parameter):
if (maek.OS === "windows") {
	maek.options.CPPFlags.push(
		`/O2`, //optimize
		//include paths for nest libraries:
		`/I${NEST_LIBS}/SDL2/include`,
		`/I${NEST_LIBS}/glm/include`,
		`/I${NEST_LIBS}/libpng/include`,
		//#disable a few warnings:
		`/wd4146`, //-1U is still unsigned
		`/wd4297`, //unforunately SDLmain is nothrow
		`/wd4100`, //unreferenced formal parameter
		`/wd4201`, //nameless struct/union
		`/wd4611`  //interaction between setjmp and C++ object destruction
	);
	maek.options.LINKLibs.push(
		`/LIBPATH:${NEST_LIBS}/SDL2/lib`, `SDL2main.lib`, `SDL2.lib`, `OpenGL32.lib`, `Shell32.lib`,
		`/LIBPATH:${NEST_LIBS}/libpng/lib`, `libpng.lib`,
		`/LIBPATH:${NEST_LIBS}/zlib/lib`, `zlib.lib`,
		`/MANIFEST:EMBED`, `/MANIFESTINPUT:set-utf8-code-page.manifest`
	);
} else if (maek.OS === "linux") {
	maek.options.CPPFlags.push(
		`-O2`, //optimize
		//include paths for nest libraries:
		`-I${NEST_LIBS}/SDL2/include/SDL2`, `-D_THREAD_SAFE`, //the output of sdl-config --cflags
		`-I${NEST_LIBS}/glm/include`,
		`-I${NEST_LIBS}/libpng/include`
	);
	maek.options.LINKLibs.push(
		//linker flags for nest libraries:
		`-L${NEST_LIBS}/SDL2/lib`, `-lSDL2`, `-lm`, `-ldl`, `-lasound`, `-lpthread`, `-lX11`, `-lXext`, `-lpthread`, `-lrt`, `-lGL`, //the output of sdl-config --static-libs
		`-L${NEST_LIBS}/libpng/lib`, `-lpng`,
		`-L${NEST_LIBS}/zlib/lib`, `-lz`
	);
} else if (maek.OS === "macos") {
	maek.options.CPPFlags.push(
		`-O2`, //optimize
		//include paths for nest libraries:
		`-I${NEST_LIBS}/SDL2/include/SDL2`, `-D_THREAD_SAFE`, //the output of sdl-config --cflags
		`-I${NEST_LIBS}/glm/include`,
		`-I${NEST_LIBS}/libpng/include`
	);
	maek.options.LINKLibs.push(
		//linker flags for nest libraries:
		`-L${NEST_LIBS}/SDL2/lib`, `-lSDL2`, `-lm`,`-liconv`, `-framework`, `CoreAudio`, `-framework`, `AudioToolbox`, `-weak_framework`, `CoreHaptics`, `-weak_framework`, `GameController`, `-framework`, `ForceFeedback`, `-lobjc`, `-framework`, `CoreVideo`, `-framework`, `Cocoa`, `-framework`, `Carbon`, `-framework`, `IOKit`, `-framework`, `OpenGL`, //the output of sdl-config --static-libs
		`-L${NEST_LIBS}/libpng/lib`, `-lpng`,
		`-L${NEST_LIBS}/zlib/lib`, `-lz`
	);
}
//use COPY to copy a file
// 'COPY(from, to)'
// from: file to copy from
// to: file to copy to
let copies = [
	maek.COPY(`${NEST_LIBS}/SDL2/dist/README-SDL.txt`, `dist/README-SDL.txt`),
	maek.COPY(`${NEST_LIBS}/libpng/dist/README-libpng.txt`, `dist/README-libpng.txt`),
];
if (maek.OS === 'windows') {
	copies.push( maek.COPY(`${NEST_LIBS}/SDL2/dist/SDL2.dll`, `dist/SDL2.dll`) );
}

//call rules on the maek object to specify tasks.
// rules generally look like:
//  output = maek.RULE_NAME(input [, output] [, {options}])

//use CHECK to print a message when something is missing
//'[targets =] CHECK(targets, prerequisites, message)'
// targets: array of targets the task produces (can include both files and ':abstract targets')
// prerequisites: array of things that must exist before manual task message is printed
// message: message to print if targets don't exist
//returns targets: the targets the rule produces

//the '[objFile =] CPP(cppFile [, objFileBase] [, options])' compiles a c++ file:
// cppFile: name of c++ file to compile
// objFileBase (optional): base name object file to produce (if not supplied, set to options.objDir + '/' + cppFile without the extension)
//returns objFile: objFileBase + a platform-dependant suffix ('.o' or '.obj')
const game_objs = [
	maek.CPP('PlayMode.cpp'),
	maek.CPP('PPU466.cpp'),
	maek.CPP('main.cpp'),
	maek.CPP('load_save_png.cpp'),
	maek.CPP('Load.cpp'),
	maek.CPP('data_path.cpp'),
	maek.CPP('Mode.cpp'),
	maek.CPP('gl_compile_program.cpp'),
	maek.CPP('GL.cpp')
];

//the '[exeFile =] LINK(objFiles, exeFileBase, [, options])' links an array of objects into an executable:
// objFiles: array of objects to link
// exeFileBase: name of executable file to produce
//returns exeFile: exeFileBase + a platform-dependant suffix (e.g., '.exe' on windows)
const game_exe = maek.LINK(game_objs, 'dist/game');

//set the default target to the game (and copy the readme files):
maek.TARGETS = [game_exe, ...copies];

//the 'RULE(targets, prerequisites[, recipe])' rule defines a Makefile-style task
// targets: array of targets the task produces (can include both files and ':abstract targets')
// prerequisites: array of targets the task waits on (can include both files and ':abstract targets')
// recipe (optional): array of commands to run (where each command is an array [exe, arg1, arg0, ...])
//returns targets: the targets the rule produces
maek.RULE([':run'], [game_exe], [
	[game_exe, '--some-command-line-option']
]);

//Note that tasks that produce ':abstract targets' are never cached.
// This is similar to how .PHONY targets behave in make.



//==========================================================================
//Now, onward to the code that makes all this work:
//  (edit this if you need to support new compilers)

function init_maek() {
	//standard libraries:
	const path = require('path').posix; //NOTE: expect posix-style paths even on windows
	const fsPromises = require('fs').promises;
	const fs = require('fs');

	//make it so that all paths/commands are relative to Maekfile.js:
	// (regardless of where you run it from)
	process.chdir(__dirname);

	//will fill in properties on this object with the public interface
	// to the build system and then return it:
	const maek = {};

	//-----------------------------------------
	//Constants:

	//cache file location:
	const CACHE_FILE = 'maek-cache.json';

	//current OS: (with slightly nicer naming than os.platform()
	const OS = (() => {
		const platform = require('os').platform();
		if (platform === 'win32') return 'windows';
		else if (platform === 'darwin') return 'macos';
		else if (platform === 'linux') return 'linux';
		else {
			console.error(`ERROR: Unrecognized platform ${os.platform()}.`);
			process.exit(1);
		}
	})();
	maek.OS = OS;

	//-----------------------------------------
	//Command line defaults:

	//maximum number of jobs to run: (change with -jN)
	maek.JOBS = require('os').cpus().length + 1;

	//targets to build by default: (change by passing target names)
	maek.TARGETS = [];

	//print extra info: (set by passing -v)
	maek.VERBOSE = false;

	//quit on first failure: (set by passing -q)
	maek.QUIT_EAGERLY = false;

	//-----------------------------------------
	//options: set to change maek rule behavior

	const DEFAULT_OPTIONS = {
		objPrefix: 'objs/', //prefix for object file paths (if not explicitly specified)
		objSuffix: (OS === 'windows' ? '.obj' : '.o'), //suffix for object files
		exeSuffix: (OS === 'windows' ? '.exe' : ''), //suffix for executable files
		depends: [], //extra dependencies; generally only set locally
		CPP: [], //the c++ compiler and any flags to start with (set below, per-OS)
		CPPFlags: [], //extra flags for c++ compiler
		LINK: [], //the linker and any flags to start with (set below, per-OS)
		LINKLibs: [], //extra -L and -l flags for linker
	}

	if (OS === 'windows') {
		DEFAULT_OPTIONS.CPP = ['cl.exe', '/nologo', '/EHsc', '/Z7', '/std:c++17', '/W4', '/WX', '/MD'];
		DEFAULT_OPTIONS.LINK = ['link.exe', '/nologo', '/SUBSYSTEM:CONSOLE', '/DEBUG:FASTLINK', '/INCREMENTAL:NO'];
	} else if (OS === 'linux') {
		DEFAULT_OPTIONS.CPP = ['g++', '-std=c++17', '-Wall', '-Werror', '-g'];
		DEFAULT_OPTIONS.LINK = ['g++', '-std=c++17', '-Wall', '-Werror', '-g'];
	} else if (OS === 'macos') {
		DEFAULT_OPTIONS.CPP = ['clang++', '-std=c++17', '-Wall', '-Werror', '-g'];
		DEFAULT_OPTIONS.LINK = ['clang++', '-std=c++17', '-Wall', '-Werror', '-g'];
	}

	//any settings here override 'DEFAULT_OPTIONS':
	maek.options = Object.assign({}, DEFAULT_OPTIONS); //shallow copy of DEFAULT_OPTIONS in case you want to console.log(maek.options) to check settings.

	//this combines DEFAULT_OPTIONS, maek.options, and localOptions:
	function combineOptions(localOptions) {
		//shallow copy of default options:
		const combined = Object.assign({}, DEFAULT_OPTIONS);
		//override with maek.options + complain on missing keys:
		for (const key of Object.keys(maek.options)) {
			if (!(key in combined)) throw new Error(`ERROR: '${key}' (in maek.options) not recognized.`);
			combined[key] = maek.options[key];
		}
		//override with localOptions + complain on missing keys:
		for (const key of Object.keys(localOptions)) {
			if (!(key in combined)) throw new Error(`ERROR: '${key}' (in local options) not recognized.`);
			combined[key] = localOptions[key];
		}
		return combined;
	}

	//-----------------------------------------
	//Data:

	//maek.tasks is a map from targets => tasks (possibly many-to-one):
	// a task is an async function that will make that target
	// (it will generally 'await' other tasks in the process)
	//
	// task.label is a human-readable name for the task (generally along the lines of "RULE 'source' -> 'target'")
	//
	// if task.keyFn is defined, it is used for caching (see below).
	// generally keyFn will return an array of the content hashes of all input and output files,
	// along with version information and parameters for external commands called by the script.
	maek.tasks = {};

	//during the build process some additional properties will be set on tasks:
	// task.cachedKey is used for caching:
	//  - after a task is run, the result of its keyFn is stored in cachedKey
	//  - a task will skipped if the result of its keyFn matches the result already in cachedKey
	//  comparisons are performed using: JSON.stringify(await task.keyFn()) === JSON.stringify(task.cachedKey)
	//
	// task.cachedKey values are loaded into the maek.tasks array from CACHE_FILE at the start of maek.update,
	// and stored into CACHE_FILE at the end of maek.update.
	//
	// task.pending is set by updateTargets() to keep track of currently-running task updates.

	//used to avoid re-hashing the same files a whole lot:
	const hashCache = {};
	let hashCacheHits = 0;

	//-----------------------------------------
	//Build rules add tasks to maek.tasks:

	//RULE adds a generic makefile-like task:
	// targets (array) are the things that get made
	// prerequisites (array) are the things that must be up-to-date before the recipe is run
	// recipe, optional (array) is a list of commands
	maek.RULE = (targets, prerequisites, recipe = []) => {
		if (!Array.isArray(targets)) throw new Error("RULE: targets must be an array.");
		if (!Array.isArray(prerequisites)) throw new Error("RULE: prerequisites must be an array.");
		if (!Array.isArray(recipe)) throw new Error("RULE: recipe must be an array.");

		const task = async () => {
			await updateTargets(prerequisites, `${task.label}`);
			let step = 1;
			for (const command of recipe) {
				await runCommand(command, `${task.label} (${step}/${recipe.length})`);
				step += 1;
			}
			for (const target of targets) {
				delete hashCache[target];
			}
		};

		if (!targets.some(target => target[0] === ':')) { //(don't cache RULE's with abstract targets)
			task.keyFn = async () => {
				await updateTargets(prerequisites, `${task.label} (keyFn)`); //prerequisites need to be ready before they can be hashed!
				return [
					...recipe,
					...(await hashFiles([...targets, ...prerequisites]))
				];
			};
		}
		task.label = `RULE ${targets[0]}`;

		for (const target of targets) {
			maek.tasks[target] = task;
		}
	};


	//CHECK adds a task that checks targets exist (after prerequisites have been created):
	// targets (array) are the things that get checked
	// prerequisites (array) are the things that must be up-to-date before the check is done
	// message (string) is printed if targets don't exist
	maek.CHECK = (targets, prerequisites, message = []) => {
		if (!Array.isArray(targets)) throw new Error("CHECK: targets must be an array.");
		if (!Array.isArray(prerequisites)) throw new Error("CHECK: prerequisites must be an array.");
		if (typeof message !== "string") throw new Error("CHECK: message must be a string.");

		const task = async () => {
			await updateTargets(prerequisites, `${task.label}`);
			const checks = targets.map(file => fsPromises.access(file, fs.constants.R_OK).catch((e) => { throw new BuildError(`missing '${file}':\n${message}`); }));
			await Promise.all(checks);
		};

		task.label = `CHECK ${targets[0]}`;

		for (const target of targets) {
			maek.tasks[target] = task;
		}
	};

	//COPY adds a task that copies a file:
	maek.COPY = (srcFile, dstFile) => {
		if (typeof srcFile !== "string") throw new Error("COPY: from should be a single file.");
		if (typeof dstFile !== "string") throw new Error("COPY: to should be a single file.");

		const task = async () => {
			await updateTargets([srcFile], `${task.label}`);
			try {
				await fsPromises.mkdir(path.dirname(dstFile), { recursive: true });
				await fsPromises.copyFile(srcFile, dstFile);
			} catch (e) {
				throw new BuildError(`Failed to copy '${srcFile}' to '${dstFile}':${e}`);
			}
		};

		task.label = `COPY ${dstFile}`;

		maek.tasks[dstFile] = task;

		return dstFile;
	};

	//maek.CPP makes an object from a c++ source file:
	// cppFile is the source file name
	// objFileBase (optional) is the output file (including any subdirectories, but not the extension)
	maek.CPP = (cppFile, objFileBase, localOptions = {}) => {
		//combine options:
		const options = combineOptions(localOptions);

		//if objFileBase isn't given, compute by trimming extension from cppFile and appending to objPrefix:
		if (typeof objFileBase === 'undefined') {
			objFileBase = path.relative('', options.objPrefix + cppFile.replace(/\.[^.]*$/, ''));
		}

		//object file gets os-dependent suffix:
		const objFile = objFileBase + options.objSuffix;

		//computed dependencies go in a '.d' file stored next to the object file:
		const depsFile = objFileBase + '.d';

		//explicit dependencies: (implicit dependencies will be computed later)
		const depends = [cppFile, ...options.depends];

		let cc, command;
		cc = [...options.CPP, ...options.CPPFlags];
		if (OS === 'linux') {
			//TODO: check on linux
			command = [...cc, '-MD', '-MT', 'x ', '-MF', depsFile, '-c', '-o', objFile, cppFile];
		} else if (OS === 'macos') {
			//TODO: check on macos
			command = [...cc, '-MD', '-MT', 'x ', '-MF', depsFile, '-c', '-o', objFile, cppFile];
		} else { //windows
			command = [...cc, '/c', `/Fo${objFile}`, '/sourceDependencies', depsFile, '/Tp', cppFile];
		}

		//will be used by loadDeps to trim explicit dependencies:
		const inDepends = {};
		for (const d of depends) {
			inDepends[d] = true;
		}
		async function loadDeps() {
			let text;
			try {
				text = await fsPromises.readFile(depsFile, { encoding: 'utf8' });
			} catch (e) {
				if (e.code === 'ENOENT') {
					return [];
				} else {
					throw e; //FLAGRANT ERROR
				}
			}

			if (OS === 'windows') {
				//parse JSON-encoded dependency info from /sourceDependencies:
				const winpath = require('path').win32;
				let paths = JSON.parse(text).Data.Includes;
				paths = paths.map(path => winpath.relative('', path).split('\\').join('/'));
				paths = paths.sort();
				const extraDepends = paths.filter(target => !(target in inDepends));
				return extraDepends;
			} else {
				//parse the makefile-style "targets : prerequisites" line from the file into a list of tokens:
				let tokens = text
					.replace(/\\?\n/g, ' ') //escaped newline (or regular newline) => whitespace
					.trim() //remove leading and trailing whitespace
					.replace(/([^\\])\s+/g, '$1\n') //run of non-escaped whitespace => single newline
					.split('\n'); //split on single newlines

				//because of the `-MT 'x '` option, expect 'x :' at the start of the rule:
				console.assert(tokens[0] === 'x');
				console.assert(tokens[1] === ':');
				tokens = tokens.slice(2); //remove the 'x :'
				tokens = tokens.sort(); //sort for consistency

				//NOTE: might want to do some path normalization here!
				const extraDepends = tokens.filter(target => !(target in inDepends));
				return extraDepends;
			}
		}

		//The actual build task:
		const task = async () => {
			//first, wait for any explicit prerequisites to build:
			await updateTargets(depends, `${task.label}`);
			//make object file:
			delete hashCache[objFile];
			delete hashCache[depsFile];
			await fsPromises.mkdir(path.dirname(objFile), { recursive: true });
			await fsPromises.mkdir(path.dirname(depsFile), { recursive: true });
			await runCommand(command, `${task.label}: compile + prerequisites`);
			//read extra dependencies and make sure they aren't targets of other rules:
			const extraDepends = await loadDeps();
			assertNontargets(extraDepends, `${task.label}`);
			//NOTE: if dynamic prerequisites are targets of other tasks there is a
			// problem whereby Maek can't know proper rule sequencing until it
			// has already run a rule.
		};

		task.keyFn = async () => {
			await updateTargets(depends, `${task.label} (keyFn)`);
			const extraDepends = await loadDeps();
			assertNontargets(extraDepends, `${task.label}`);
			return [
				command,
				...(await hashFiles([await findExe(command), objFile, depsFile, ...depends, ...extraDepends]))
			];
		};

		task.label = `CPP ${objFile}`;

		maek.tasks[objFile] = task;

		return objFile;
	};


	//maek.LINK links an executable file from a collection of object files:
	// objFiles is an array of object file names
	// exeFileBase is the base name of the executable file ('.exe' will be added on windows)
	maek.LINK = (objFiles, exeFileBase, localOptions = {}) => {
		const options = combineOptions(localOptions);

		const exeFile = exeFileBase + options.exeSuffix;

		let link, linkCommand;
		link = [...options.LINK];
		if (OS === 'linux') {
			linkCommand = [...link, '-o', exeFile, ...objFiles, ...options.LINKLibs];
		} else if (OS === 'macos') {
			linkCommand = [...link, '-o', exeFile, ...objFiles, ...options.LINKLibs];
		} else {
			linkCommand = [...link, `/out:${exeFile}`, ...objFiles, ...options.LINKLibs];
		}
		const depends = [...objFiles, ...options.depends];

		const task = async () => {
			//first, wait for all requested object files to build:
			await updateTargets(depends, `${task.label}`);

			//then link:
			delete hashCache[exeFile];
			await fsPromises.mkdir(path.dirname(exeFile), { recursive: true });
			await runCommand(linkCommand, `${task.label}: link`);
		};

		task.keyFn = async () => {
			await updateTargets(depends, `${task.label} (keyFn)`);
			return [
				linkCommand,
				...(await hashFiles([await findExe(linkCommand), exeFile, ...depends]))
			];
		};

		task.label = `LINK ${exeFile}`;

		maek.tasks[exeFile] = task;

		return exeFile;
	};

	//---------------------------------
	//helper functions used by the build rules:

	//says something went wrong in building -- should fail loudly:
	class BuildError extends Error {
		constructor(message) {
			super(message);
		}
	}

	//says something went wrong elsewhere and this job is getting cleaned up -- should fail quietly:
	class Cancelled extends Error {
		constructor() {
			super("Cancelled all tasks.");
		}
	}

	//when set, stop build (by, e.g., failing any remaining job() invocations):
	let CANCEL_ALL_TASKS = false;

	//updateTargets takes a list of targets and updates them as needed.
	async function updateTargets(targets, from) {
		const pending = [];
		for (const target of targets) {
			//if target has an associated task, wait on that task:
			if (target in maek.tasks) {
				const task = maek.tasks[target];
				// launch task if not already pending:
				if (!('pending' in task)) {
					task.from = from;
					task.pending = (async () => {
						try {
							//check for cache hit:
							if ('cachedKey' in task && 'keyFn' in task) {
								const key = await task.keyFn();
								if (JSON.stringify(key) === JSON.stringify(task.cachedKey)) {
									if (maek.VERBOSE) console.log(`${task.label}: already in cache.`);
									return;
								} else {
									const a = JSON.stringify(key);
									const b = JSON.stringify(task.cachedKey);
									for (let i = 0; i < a.length; ++i) {
										if (a[i] !== b[i]) {
											const begin = Math.max(0, i - 20);
											const end = i + 20;
											if (maek.VERBOSE) console.log(`${task.label}: key mis-match new[${begin}:${end}] = ${a.substr(begin, end - begin)} vs old[${begin}:${end}] = ${b.substr(begin, end - begin)}`);
											break;
										}
									}
								}
							}
							//on cache miss, run task:
							await task();
							//and update cache:
							if ('keyFn' in task) {
								task.cachedKey = await task.keyFn();
							}
						} catch (e) {
							if (e instanceof BuildError) {
								console.error(`!!! FAILED [${task.label}] ${e.message}`);
								task.failed = true;
								//if -q flag is set, immediately cancel all jobs:
								if (maek.QUIT_EAGERLY) {
									CANCEL_ALL_TASKS = true; //set flag so obs cancel themselves
								}
							} else if (maek.QUIT_EAGERLY && e instanceof Cancelled) {
								//if this failed because a component job was cancelled, make a note:
								task.failed = true;
								if (maek.VERBOSE) console.error(`CANCELED [${task.label}]`);
							} else {
								//don't expect any other exceptions, but if they do arise, re-throw 'em:
								throw e;
							}
						}
					})();
				}
				pending.push(task.pending);
				//otherwise, if target is abstract, complain because it isn't known:
			} else if (target[0] === ':') {
				throw new BuildError(`Target '${target}' (requested by ${from}) is abstract but doesn't have a task.`);
				//otherwise, target is a file, so check that it exists:
			} else {
				pending.push(
					fsPromises.access(target, fs.constants.R_OK).catch((e) => {
						throw new BuildError(`Target '${target}' (requested by ${from}) doesn't exist and doesn't have a task to make it.`);
					})
				);
			}
		}

		//resolve all the build/check tasks before returning:
		await Promise.all(pending);

		//if the CANCEL_ALL_TASKS flag is set, don't report further errors, just abort:
		if (CANCEL_ALL_TASKS) throw new Cancelled();

		//check for any build failures:
		for (const target of targets) {
			if (target in maek.tasks) {
				if (maek.tasks[target].failed) {
					throw new BuildError(`for lack of ${target}`);
				}
			}
		}
	}

	//'job' says the contained function is an async job that should count against the JOBS limit:
	// returns a promise that resolves to the result of jobFn() (or rejects if jobFn() throws)
	// will always wait until at least the next tick to run jobFn()
	function job(jobFn) {
		//keep count of active jobs and list of pending jobs:
		if (!('active' in job)) job.active = 0;
		if (!('pending' in job)) job.pending = [];

		//helper that runs a job on the pending queue:
		async function schedule() {
			if (job.active < maek.JOBS && job.pending.length) {
				job.active += 1;
				//DEBUG: console.log(`[${job.active}/${JOBS} active, ${job.pending.length} pending]`);
				const next = job.pending.shift();
				try {
					if (CANCEL_ALL_TASKS) throw new Cancelled();
					next.resolve(await next.jobFn());
				} catch (e) {
					next.reject(e);
				}
				job.active -= 1;
				process.nextTick(schedule);
			}
		}

		//make sure to check for executable jobs next tick:
		process.nextTick(schedule);

		//throw job onto pending queue:
		return new Promise((resolve, reject) => {
			job.pending.push({ jobFn, resolve, reject });
		});
	}

	//findExe looks up a command in the PATH (so, e.g., one can hash compiler binaries)
	async function findExe(command) {
		const osPath = require('path');
		let PATH;
		if (OS === 'windows') {
			PATH = process.env.PATH.split(';');
		} else {
			PATH = process.env.PATH.split(':');
		}
		for (const prefix of PATH) {
			const exe = osPath.resolve(prefix, command[0]);
			try {
				await fsPromises.access(exe, fs.constants.X_OK);
				return exe;
			} catch (e) {
				if (e.code === 'ENOENT') continue;
				else throw e;
			}
		}
		throw new BuildError(`Couldn't find file for command '${command[0]}'`);
		return "?";
	}

	//runCommand runs a command:
	async function runCommand(command, message) {
		await job(async () => {
			if (typeof message !== 'undefined') {
				console.log('\x1b[90m' + message + '\x1b[0m');
			}

			//print a command in a way that can be copied to a shell to run:
			let prettyCommand = '';
			for (const token of command) {
				if (prettyCommand !== '') prettyCommand += ' ';
				if (/[ \t\n!"'$&()*,;<>?[\\\]^`{|}~]/.test(token)
					|| token[0] === '='
					|| token[0] === '#') {
					//special characters => need to quote:
					prettyCommand += "'" + token.replace(/'/g, "'\\''") + "'";
				} else {
					prettyCommand += token;
				}
			}
			console.log('   ' + prettyCommand);

			//actually run the command:
			const child_process = require('child_process');

			//package as a promise and await it finishing:
			await new Promise((resolve, reject) => {
				const proc = child_process.spawn(command[0], command.slice(1), {
					shell: false,
					stdio: ['ignore', 'inherit', 'inherit']
				});
				proc.on('exit', (code, signal) => {
					if (code !== 0) {
						process.stderr.write(`\n`);
						reject(new BuildError(`exit ${code} from:\n    \x1b[31m${prettyCommand}\x1b[0m\n`));
					} else {
						resolve();
					}
				});
				proc.on('error', (err) => {
					reject(new BuildError(`${err.message} from:\n    ${prettyCommand}`));
				});
			});
		});
	}

	//assertNontargets makes sure none of the mentioned prerequisites are targets of tasks:
	function assertNontargets(prerequisites, ruleName) {
		let errorFiles = [];
		for (const target of prerequisites) {
			if ('target' in maek.tasks) {
				errorFiles.push(target);
			}
		}
		if (errorFiles.length) {
			throw new BuildError(`the following *generated* files are required but not mentioned as dependancies:\n  ${errorFiles.join('\n  ')}`);
		}
	}

	//return a ['file:base64hash', 'file2:whateverHash', 'file3:etcstuff'] array,
	// representing the contents of a list of targets (with ':abstract' targets removed)
	async function hashFiles(targets) {
		const crypto = require('crypto');

		const files = targets.filter(target => target[0] !== ':');

		//helper that will hash a single file: (non-existent files get special hash 'x')
		async function hashFile(file) {
			if (file in hashCache) {
				hashCacheHits += 1;
				return hashCache[file];
			}

			//would likely be more efficient to use a pipe with large files,
			//but this code is a bit more readable:
			const hash = await new Promise((resolve, reject) => {
				fs.readFile(file, (err, data) => {
					if (err) {
						//if failed to read file, report hash as 'x':
						if (err.code != "ENOENT") {
							console.warn(`Failed to hash ${file} because of unexpected error ${err}`); //DEBUG
						}
						resolve(`${file}:x`);
					} else {
						//otherwise, report base64-encoded md5sum of file data:
						const hash = crypto.createHash('md5');
						hash.update(data);
						resolve(`${file}:${hash.digest('base64')}`);
					}
				});
			});

			hashCache[file] = hash;
			return hash;
		}

		//get all hashes:
		if (OS === 'windows') {
			//work in serial since otherwise windows can run out of file descriptors:
			const hashes = [];
			for (let file of files) {
				hashes.push(await hashFile(file));
			}
			return hashes;
		} else {
			return await Promise.all(files.map(hashFile));
		}
	}

	//---------------------------------
	//Public Interface:

	maek.update = async (targets) => {
		const performance = require('perf_hooks').performance;
		const before = performance.now();
		console.log(` -- Maek v0.1 on ${OS} with ${maek.JOBS} max jobs updating '${targets.join("', '")}'...`);

		//clean up any stale cachedKey values:
		for (const target of Object.keys(maek.tasks)) {
			delete maek.tasks[target].cachedKey;
		}
		//load cachedKey values from cache file:
		try {
			const cache = JSON.parse(fs.readFileSync(CACHE_FILE, { encoding: 'utf8' }));
			let assigned = 0;
			let removed = 0;
			for (const target of Object.keys(cache)) {
				if (target in maek.tasks) {
					maek.tasks[target].cachedKey = cache[target];
					assigned += 1;
				} else {
					removed += 1;
				}
			}
			if (maek.VERBOSE) console.log(` -- Loaded cache from '${CACHE_FILE}'; assigned ${assigned} targets and removed ${removed} stale entries.`);
		} catch (e) {
			if (maek.VERBOSE) console.log(` --  No cache loaded; starting fresh.`);
			if (e.code !== 'ENOENT') {
				console.warn(`By the way, the reason the loading failed was the following unexpected error:`, e);
			}
		}

		//actually do the build:
		let failed = false;
		try {
			await updateTargets(targets, 'user');
			const after = performance.now();
			console.log(` -- SUCCESS: Target(s) '${targets.join("', '")}' brought up to date in ${((after - before) / 1000.0).toFixed(3)} seconds.`);
		} catch (e) {
			if (e instanceof BuildError) {
				console.error(` -- FAILED: ${e.message}`);
				process.exitCode = 1;
			} else if (e instanceof Cancelled) {
				console.error(` -- CANCELLED`);
				process.exitCode = 1;
			} else {
				throw e;
			}
		}

		//store cachedKey values:
		const cache = {};
		let stored = 0;
		for (const target of Object.keys(maek.tasks)) {
			if ('cachedKey' in maek.tasks[target]) {
				cache[target] = maek.tasks[target].cachedKey;
				stored += 1;
			}
		}
		if (maek.VERBOSE) console.log(` -- Writing cache with ${stored} entries to '${CACHE_FILE}'...`);
		fs.writeFileSync(CACHE_FILE, JSON.stringify(cache), { encoding: 'utf8' });

		if (maek.VERBOSE) console.log(` -- hashCache ended up with ${Object.keys(hashCache).length} items and handled ${hashCacheHits} hits.`);
	};

	//automatically call 'update' once the main body of the script has finished running:
	process.nextTick(() => {
		//parse the command line:
		let targets = [];
		for (let argi = 2; argi < process.argv.length; ++argi) {
			const arg = process.argv[argi];
			if (arg === '--') { //-- target target ...
				//the rest of the command line is targets:
				targets.push(...process.argv.slice(argi + 1));
				console.log(`Added targets ${process.argv.slice(argi + 1)}.`);
				break;
			} else if (/^-j[\d+]$/.test(arg)) { //-jN
				//set max jobs
				maek.JOBS = parseInt(arg.substr(2));
				console.log(`Set JOBS to ${maek.JOBS}.`);
			} else if (arg === '-v') {
				//set verbose output
				maek.VERBOSE = true;
			} else if (arg === '-q') {
				//set quit on on first error:
				maek.QUIT_EAGERLY = true;
			} else if (arg.startsWith('-')) { //unrecognized option
				console.error(`Unrecognized option '${arg}'.`);
				process.exit(1);
			} else if (!arg.startsWith('-')) { //a target name
				console.log(`Added target ${arg}.`);
				targets.push(arg);
			}
		}
		if (targets.length !== 0) {
			maek.TARGETS = targets;
		}
		if (maek.TARGETS.length === 0) {
			console.warn("No targets specified on command line and no default targets.");
		}

		maek.update(maek.TARGETS);
	});

	return maek;
}
