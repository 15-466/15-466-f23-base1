#include "GL.hpp"

#include <SDL.h>
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
	#define DO(fn) \
		fn = (decltype(fn))SDL_GL_GetProcAddress(#fn); \
		if (!fn) { \
			throw std::runtime_error("Error binding " #fn); \
		}
#else
	#define DO(fn)
#endif

void init_GL() {
	DO(glDrawRangeElements)
	DO(glTexImage3D)
	DO(glTexSubImage3D)
	DO(glCopyTexSubImage3D)
	DO(glActiveTexture)
	DO(glSampleCoverage)
	DO(glCompressedTexImage3D)
	DO(glCompressedTexImage2D)
	DO(glCompressedTexImage1D)
	DO(glCompressedTexSubImage3D)
	DO(glCompressedTexSubImage2D)
	DO(glCompressedTexSubImage1D)
	DO(glGetCompressedTexImage)
	DO(glBlendFuncSeparate)
	DO(glMultiDrawArrays)
	DO(glMultiDrawElements)
	DO(glPointParameterf)
	DO(glPointParameterfv)
	DO(glPointParameteri)
	DO(glPointParameteriv)
	DO(glBlendColor)
	DO(glBlendEquation)
	DO(glGenQueries)
	DO(glDeleteQueries)
	DO(glIsQuery)
	DO(glBeginQuery)
	DO(glEndQuery)
	DO(glGetQueryiv)
	DO(glGetQueryObjectiv)
	DO(glGetQueryObjectuiv)
	DO(glBindBuffer)
	DO(glDeleteBuffers)
	DO(glGenBuffers)
	DO(glIsBuffer)
	DO(glBufferData)
	DO(glBufferSubData)
	DO(glGetBufferSubData)
	DO(glMapBuffer)
	DO(glUnmapBuffer)
	DO(glGetBufferParameteriv)
	DO(glGetBufferPointerv)
	DO(glBlendEquationSeparate)
	DO(glDrawBuffers)
	DO(glStencilOpSeparate)
	DO(glStencilFuncSeparate)
	DO(glStencilMaskSeparate)
	DO(glAttachShader)
	DO(glBindAttribLocation)
	DO(glCompileShader)
	DO(glCreateProgram)
	DO(glCreateShader)
	DO(glDeleteProgram)
	DO(glDeleteShader)
	DO(glDetachShader)
	DO(glDisableVertexAttribArray)
	DO(glEnableVertexAttribArray)
	DO(glGetActiveAttrib)
	DO(glGetActiveUniform)
	DO(glGetAttachedShaders)
	DO(glGetAttribLocation)
	DO(glGetProgramiv)
	DO(glGetProgramInfoLog)
	DO(glGetShaderiv)
	DO(glGetShaderInfoLog)
	DO(glGetShaderSource)
	DO(glGetUniformLocation)
	DO(glGetUniformfv)
	DO(glGetUniformiv)
	DO(glGetVertexAttribdv)
	DO(glGetVertexAttribfv)
	DO(glGetVertexAttribiv)
	DO(glGetVertexAttribPointerv)
	DO(glIsProgram)
	DO(glIsShader)
	DO(glLinkProgram)
	DO(glShaderSource)
	DO(glUseProgram)
	DO(glUniform1f)
	DO(glUniform2f)
	DO(glUniform3f)
	DO(glUniform4f)
	DO(glUniform1i)
	DO(glUniform2i)
	DO(glUniform3i)
	DO(glUniform4i)
	DO(glUniform1fv)
	DO(glUniform2fv)
	DO(glUniform3fv)
	DO(glUniform4fv)
	DO(glUniform1iv)
	DO(glUniform2iv)
	DO(glUniform3iv)
	DO(glUniform4iv)
	DO(glUniformMatrix2fv)
	DO(glUniformMatrix3fv)
	DO(glUniformMatrix4fv)
	DO(glValidateProgram)
	DO(glVertexAttrib1d)
	DO(glVertexAttrib1dv)
	DO(glVertexAttrib1f)
	DO(glVertexAttrib1fv)
	DO(glVertexAttrib1s)
	DO(glVertexAttrib1sv)
	DO(glVertexAttrib2d)
	DO(glVertexAttrib2dv)
	DO(glVertexAttrib2f)
	DO(glVertexAttrib2fv)
	DO(glVertexAttrib2s)
	DO(glVertexAttrib2sv)
	DO(glVertexAttrib3d)
	DO(glVertexAttrib3dv)
	DO(glVertexAttrib3f)
	DO(glVertexAttrib3fv)
	DO(glVertexAttrib3s)
	DO(glVertexAttrib3sv)
	DO(glVertexAttrib4Nbv)
	DO(glVertexAttrib4Niv)
	DO(glVertexAttrib4Nsv)
	DO(glVertexAttrib4Nub)
	DO(glVertexAttrib4Nubv)
	DO(glVertexAttrib4Nuiv)
	DO(glVertexAttrib4Nusv)
	DO(glVertexAttrib4bv)
	DO(glVertexAttrib4d)
	DO(glVertexAttrib4dv)
	DO(glVertexAttrib4f)
	DO(glVertexAttrib4fv)
	DO(glVertexAttrib4iv)
	DO(glVertexAttrib4s)
	DO(glVertexAttrib4sv)
	DO(glVertexAttrib4ubv)
	DO(glVertexAttrib4uiv)
	DO(glVertexAttrib4usv)
	DO(glVertexAttribPointer)
	DO(glUniformMatrix2x3fv)
	DO(glUniformMatrix3x2fv)
	DO(glUniformMatrix2x4fv)
	DO(glUniformMatrix4x2fv)
	DO(glUniformMatrix3x4fv)
	DO(glUniformMatrix4x3fv)
	DO(glColorMaski)
	DO(glGetBooleani_v)
	DO(glGetIntegeri_v)
	DO(glEnablei)
	DO(glDisablei)
	DO(glIsEnabledi)
	DO(glBeginTransformFeedback)
	DO(glEndTransformFeedback)
	DO(glBindBufferRange)
	DO(glBindBufferBase)
	DO(glTransformFeedbackVaryings)
	DO(glGetTransformFeedbackVarying)
	DO(glClampColor)
	DO(glBeginConditionalRender)
	DO(glEndConditionalRender)
	DO(glVertexAttribIPointer)
	DO(glGetVertexAttribIiv)
	DO(glGetVertexAttribIuiv)
	DO(glVertexAttribI1i)
	DO(glVertexAttribI2i)
	DO(glVertexAttribI3i)
	DO(glVertexAttribI4i)
	DO(glVertexAttribI1ui)
	DO(glVertexAttribI2ui)
	DO(glVertexAttribI3ui)
	DO(glVertexAttribI4ui)
	DO(glVertexAttribI1iv)
	DO(glVertexAttribI2iv)
	DO(glVertexAttribI3iv)
	DO(glVertexAttribI4iv)
	DO(glVertexAttribI1uiv)
	DO(glVertexAttribI2uiv)
	DO(glVertexAttribI3uiv)
	DO(glVertexAttribI4uiv)
	DO(glVertexAttribI4bv)
	DO(glVertexAttribI4sv)
	DO(glVertexAttribI4ubv)
	DO(glVertexAttribI4usv)
	DO(glGetUniformuiv)
	DO(glBindFragDataLocation)
	DO(glGetFragDataLocation)
	DO(glUniform1ui)
	DO(glUniform2ui)
	DO(glUniform3ui)
	DO(glUniform4ui)
	DO(glUniform1uiv)
	DO(glUniform2uiv)
	DO(glUniform3uiv)
	DO(glUniform4uiv)
	DO(glTexParameterIiv)
	DO(glTexParameterIuiv)
	DO(glGetTexParameterIiv)
	DO(glGetTexParameterIuiv)
	DO(glClearBufferiv)
	DO(glClearBufferuiv)
	DO(glClearBufferfv)
	DO(glClearBufferfi)
	DO(glGetStringi)
	DO(glIsRenderbuffer)
	DO(glBindRenderbuffer)
	DO(glDeleteRenderbuffers)
	DO(glGenRenderbuffers)
	DO(glRenderbufferStorage)
	DO(glGetRenderbufferParameteriv)
	DO(glIsFramebuffer)
	DO(glBindFramebuffer)
	DO(glDeleteFramebuffers)
	DO(glGenFramebuffers)
	DO(glCheckFramebufferStatus)
	DO(glFramebufferTexture1D)
	DO(glFramebufferTexture2D)
	DO(glFramebufferTexture3D)
	DO(glFramebufferRenderbuffer)
	DO(glGetFramebufferAttachmentParameteriv)
	DO(glGenerateMipmap)
	DO(glBlitFramebuffer)
	DO(glRenderbufferStorageMultisample)
	DO(glFramebufferTextureLayer)
	DO(glMapBufferRange)
	DO(glFlushMappedBufferRange)
	DO(glBindVertexArray)
	DO(glDeleteVertexArrays)
	DO(glGenVertexArrays)
	DO(glIsVertexArray)
	DO(glDrawArraysInstanced)
	DO(glDrawElementsInstanced)
	DO(glTexBuffer)
	DO(glPrimitiveRestartIndex)
	DO(glCopyBufferSubData)
	DO(glGetUniformIndices)
	DO(glGetActiveUniformsiv)
	DO(glGetActiveUniformName)
	DO(glGetUniformBlockIndex)
	DO(glGetActiveUniformBlockiv)
	DO(glGetActiveUniformBlockName)
	DO(glUniformBlockBinding)
	DO(glDrawElementsBaseVertex)
	DO(glDrawRangeElementsBaseVertex)
	DO(glDrawElementsInstancedBaseVertex)
	DO(glMultiDrawElementsBaseVertex)
	DO(glProvokingVertex)
	DO(glFenceSync)
	DO(glIsSync)
	DO(glDeleteSync)
	DO(glClientWaitSync)
	DO(glWaitSync)
	DO(glGetInteger64v)
	DO(glGetSynciv)
	DO(glGetInteger64i_v)
	DO(glGetBufferParameteri64v)
	DO(glFramebufferTexture)
	DO(glTexImage2DMultisample)
	DO(glTexImage3DMultisample)
	DO(glGetMultisamplefv)
	DO(glSampleMaski)
	DO(glBindFragDataLocationIndexed)
	DO(glGetFragDataIndex)
	DO(glGenSamplers)
	DO(glDeleteSamplers)
	DO(glIsSampler)
	DO(glBindSampler)
	DO(glSamplerParameteri)
	DO(glSamplerParameteriv)
	DO(glSamplerParameterf)
	DO(glSamplerParameterfv)
	DO(glSamplerParameterIiv)
	DO(glSamplerParameterIuiv)
	DO(glGetSamplerParameteriv)
	DO(glGetSamplerParameterIiv)
	DO(glGetSamplerParameterfv)
	DO(glGetSamplerParameterIuiv)
	DO(glQueryCounter)
	DO(glGetQueryObjecti64v)
	DO(glGetQueryObjectui64v)
	DO(glVertexAttribDivisor)
	DO(glVertexAttribP1ui)
	DO(glVertexAttribP1uiv)
	DO(glVertexAttribP2ui)
	DO(glVertexAttribP2uiv)
	DO(glVertexAttribP3ui)
	DO(glVertexAttribP3uiv)
	DO(glVertexAttribP4ui)
	DO(glVertexAttribP4uiv)
}
#ifdef _WIN32
	 void (APIENTRYFP glDrawRangeElements) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
	 void (APIENTRYFP glTexImage3D) (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
	 void (APIENTRYFP glTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
	 void (APIENTRYFP glCopyTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	 void (APIENTRYFP glActiveTexture) (GLenum texture);
	 void (APIENTRYFP glSampleCoverage) (GLfloat value, GLboolean invert);
	 void (APIENTRYFP glCompressedTexImage3D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glCompressedTexImage2D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glCompressedTexImage1D) (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glCompressedTexSubImage3D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glCompressedTexSubImage2D) (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glCompressedTexSubImage1D) (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
	 void (APIENTRYFP glGetCompressedTexImage) (GLenum target, GLint level, void *img);
	 void (APIENTRYFP glBlendFuncSeparate) (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	 void (APIENTRYFP glMultiDrawArrays) (GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
	 void (APIENTRYFP glMultiDrawElements) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
	 void (APIENTRYFP glPointParameterf) (GLenum pname, GLfloat param);
	 void (APIENTRYFP glPointParameterfv) (GLenum pname, const GLfloat *params);
	 void (APIENTRYFP glPointParameteri) (GLenum pname, GLint param);
	 void (APIENTRYFP glPointParameteriv) (GLenum pname, const GLint *params);
	 void (APIENTRYFP glBlendColor) (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	 void (APIENTRYFP glBlendEquation) (GLenum mode);
	 void (APIENTRYFP glGenQueries) (GLsizei n, GLuint *ids);
	 void (APIENTRYFP glDeleteQueries) (GLsizei n, const GLuint *ids);
	 GLboolean (APIENTRYFP glIsQuery) (GLuint id);
	 void (APIENTRYFP glBeginQuery) (GLenum target, GLuint id);
	 void (APIENTRYFP glEndQuery) (GLenum target);
	 void (APIENTRYFP glGetQueryiv) (GLenum target, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetQueryObjectiv) (GLuint id, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetQueryObjectuiv) (GLuint id, GLenum pname, GLuint *params);
	 void (APIENTRYFP glBindBuffer) (GLenum target, GLuint buffer);
	 void (APIENTRYFP glDeleteBuffers) (GLsizei n, const GLuint *buffers);
	 void (APIENTRYFP glGenBuffers) (GLsizei n, GLuint *buffers);
	 GLboolean (APIENTRYFP glIsBuffer) (GLuint buffer);
	 void (APIENTRYFP glBufferData) (GLenum target, GLsizeiptr size, const void *data, GLenum usage);
	 void (APIENTRYFP glBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
	 void (APIENTRYFP glGetBufferSubData) (GLenum target, GLintptr offset, GLsizeiptr size, void *data);
	 void *(APIENTRYFP glMapBuffer) (GLenum target, GLenum access);
	 GLboolean (APIENTRYFP glUnmapBuffer) (GLenum target);
	 void (APIENTRYFP glGetBufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetBufferPointerv) (GLenum target, GLenum pname, void **params);
	 void (APIENTRYFP glBlendEquationSeparate) (GLenum modeRGB, GLenum modeAlpha);
	 void (APIENTRYFP glDrawBuffers) (GLsizei n, const GLenum *bufs);
	 void (APIENTRYFP glStencilOpSeparate) (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	 void (APIENTRYFP glStencilFuncSeparate) (GLenum face, GLenum func, GLint ref, GLuint mask);
	 void (APIENTRYFP glStencilMaskSeparate) (GLenum face, GLuint mask);
	 void (APIENTRYFP glAttachShader) (GLuint program, GLuint shader);
	 void (APIENTRYFP glBindAttribLocation) (GLuint program, GLuint index, const GLchar *name);
	 void (APIENTRYFP glCompileShader) (GLuint shader);
	 GLuint (APIENTRYFP glCreateProgram) (void);
	 GLuint (APIENTRYFP glCreateShader) (GLenum type);
	 void (APIENTRYFP glDeleteProgram) (GLuint program);
	 void (APIENTRYFP glDeleteShader) (GLuint shader);
	 void (APIENTRYFP glDetachShader) (GLuint program, GLuint shader);
	 void (APIENTRYFP glDisableVertexAttribArray) (GLuint index);
	 void (APIENTRYFP glEnableVertexAttribArray) (GLuint index);
	 void (APIENTRYFP glGetActiveAttrib) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	 void (APIENTRYFP glGetActiveUniform) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
	 void (APIENTRYFP glGetAttachedShaders) (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
	 GLint (APIENTRYFP glGetAttribLocation) (GLuint program, const GLchar *name);
	 void (APIENTRYFP glGetProgramiv) (GLuint program, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetProgramInfoLog) (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	 void (APIENTRYFP glGetShaderiv) (GLuint shader, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetShaderInfoLog) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
	 void (APIENTRYFP glGetShaderSource) (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
	 GLint (APIENTRYFP glGetUniformLocation) (GLuint program, const GLchar *name);
	 void (APIENTRYFP glGetUniformfv) (GLuint program, GLint location, GLfloat *params);
	 void (APIENTRYFP glGetUniformiv) (GLuint program, GLint location, GLint *params);
	 void (APIENTRYFP glGetVertexAttribdv) (GLuint index, GLenum pname, GLdouble *params);
	 void (APIENTRYFP glGetVertexAttribfv) (GLuint index, GLenum pname, GLfloat *params);
	 void (APIENTRYFP glGetVertexAttribiv) (GLuint index, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetVertexAttribPointerv) (GLuint index, GLenum pname, void **pointer);
	 GLboolean (APIENTRYFP glIsProgram) (GLuint program);
	 GLboolean (APIENTRYFP glIsShader) (GLuint shader);
	 void (APIENTRYFP glLinkProgram) (GLuint program);
	 void (APIENTRYFP glShaderSource) (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
	 void (APIENTRYFP glUseProgram) (GLuint program);
	 void (APIENTRYFP glUniform1f) (GLint location, GLfloat v0);
	 void (APIENTRYFP glUniform2f) (GLint location, GLfloat v0, GLfloat v1);
	 void (APIENTRYFP glUniform3f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	 void (APIENTRYFP glUniform4f) (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	 void (APIENTRYFP glUniform1i) (GLint location, GLint v0);
	 void (APIENTRYFP glUniform2i) (GLint location, GLint v0, GLint v1);
	 void (APIENTRYFP glUniform3i) (GLint location, GLint v0, GLint v1, GLint v2);
	 void (APIENTRYFP glUniform4i) (GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	 void (APIENTRYFP glUniform1fv) (GLint location, GLsizei count, const GLfloat *value);
	 void (APIENTRYFP glUniform2fv) (GLint location, GLsizei count, const GLfloat *value);
	 void (APIENTRYFP glUniform3fv) (GLint location, GLsizei count, const GLfloat *value);
	 void (APIENTRYFP glUniform4fv) (GLint location, GLsizei count, const GLfloat *value);
	 void (APIENTRYFP glUniform1iv) (GLint location, GLsizei count, const GLint *value);
	 void (APIENTRYFP glUniform2iv) (GLint location, GLsizei count, const GLint *value);
	 void (APIENTRYFP glUniform3iv) (GLint location, GLsizei count, const GLint *value);
	 void (APIENTRYFP glUniform4iv) (GLint location, GLsizei count, const GLint *value);
	 void (APIENTRYFP glUniformMatrix2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glValidateProgram) (GLuint program);
	 void (APIENTRYFP glVertexAttrib1d) (GLuint index, GLdouble x);
	 void (APIENTRYFP glVertexAttrib1dv) (GLuint index, const GLdouble *v);
	 void (APIENTRYFP glVertexAttrib1f) (GLuint index, GLfloat x);
	 void (APIENTRYFP glVertexAttrib1fv) (GLuint index, const GLfloat *v);
	 void (APIENTRYFP glVertexAttrib1s) (GLuint index, GLshort x);
	 void (APIENTRYFP glVertexAttrib1sv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttrib2d) (GLuint index, GLdouble x, GLdouble y);
	 void (APIENTRYFP glVertexAttrib2dv) (GLuint index, const GLdouble *v);
	 void (APIENTRYFP glVertexAttrib2f) (GLuint index, GLfloat x, GLfloat y);
	 void (APIENTRYFP glVertexAttrib2fv) (GLuint index, const GLfloat *v);
	 void (APIENTRYFP glVertexAttrib2s) (GLuint index, GLshort x, GLshort y);
	 void (APIENTRYFP glVertexAttrib2sv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttrib3d) (GLuint index, GLdouble x, GLdouble y, GLdouble z);
	 void (APIENTRYFP glVertexAttrib3dv) (GLuint index, const GLdouble *v);
	 void (APIENTRYFP glVertexAttrib3f) (GLuint index, GLfloat x, GLfloat y, GLfloat z);
	 void (APIENTRYFP glVertexAttrib3fv) (GLuint index, const GLfloat *v);
	 void (APIENTRYFP glVertexAttrib3s) (GLuint index, GLshort x, GLshort y, GLshort z);
	 void (APIENTRYFP glVertexAttrib3sv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttrib4Nbv) (GLuint index, const GLbyte *v);
	 void (APIENTRYFP glVertexAttrib4Niv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttrib4Nsv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttrib4Nub) (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
	 void (APIENTRYFP glVertexAttrib4Nubv) (GLuint index, const GLubyte *v);
	 void (APIENTRYFP glVertexAttrib4Nuiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttrib4Nusv) (GLuint index, const GLushort *v);
	 void (APIENTRYFP glVertexAttrib4bv) (GLuint index, const GLbyte *v);
	 void (APIENTRYFP glVertexAttrib4d) (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
	 void (APIENTRYFP glVertexAttrib4dv) (GLuint index, const GLdouble *v);
	 void (APIENTRYFP glVertexAttrib4f) (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	 void (APIENTRYFP glVertexAttrib4fv) (GLuint index, const GLfloat *v);
	 void (APIENTRYFP glVertexAttrib4iv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttrib4s) (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
	 void (APIENTRYFP glVertexAttrib4sv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttrib4ubv) (GLuint index, const GLubyte *v);
	 void (APIENTRYFP glVertexAttrib4uiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttrib4usv) (GLuint index, const GLushort *v);
	 void (APIENTRYFP glVertexAttribPointer) (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
	 void (APIENTRYFP glUniformMatrix2x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix3x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix2x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix4x2fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix3x4fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glUniformMatrix4x3fv) (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
	 void (APIENTRYFP glColorMaski) (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
	 void (APIENTRYFP glGetBooleani_v) (GLenum target, GLuint index, GLboolean *data);
	 void (APIENTRYFP glGetIntegeri_v) (GLenum target, GLuint index, GLint *data);
	 void (APIENTRYFP glEnablei) (GLenum target, GLuint index);
	 void (APIENTRYFP glDisablei) (GLenum target, GLuint index);
	 GLboolean (APIENTRYFP glIsEnabledi) (GLenum target, GLuint index);
	 void (APIENTRYFP glBeginTransformFeedback) (GLenum primitiveMode);
	 void (APIENTRYFP glEndTransformFeedback) (void);
	 void (APIENTRYFP glBindBufferRange) (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	 void (APIENTRYFP glBindBufferBase) (GLenum target, GLuint index, GLuint buffer);
	 void (APIENTRYFP glTransformFeedbackVaryings) (GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
	 void (APIENTRYFP glGetTransformFeedbackVarying) (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
	 void (APIENTRYFP glClampColor) (GLenum target, GLenum clamp);
	 void (APIENTRYFP glBeginConditionalRender) (GLuint id, GLenum mode);
	 void (APIENTRYFP glEndConditionalRender) (void);
	 void (APIENTRYFP glVertexAttribIPointer) (GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
	 void (APIENTRYFP glGetVertexAttribIiv) (GLuint index, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetVertexAttribIuiv) (GLuint index, GLenum pname, GLuint *params);
	 void (APIENTRYFP glVertexAttribI1i) (GLuint index, GLint x);
	 void (APIENTRYFP glVertexAttribI2i) (GLuint index, GLint x, GLint y);
	 void (APIENTRYFP glVertexAttribI3i) (GLuint index, GLint x, GLint y, GLint z);
	 void (APIENTRYFP glVertexAttribI4i) (GLuint index, GLint x, GLint y, GLint z, GLint w);
	 void (APIENTRYFP glVertexAttribI1ui) (GLuint index, GLuint x);
	 void (APIENTRYFP glVertexAttribI2ui) (GLuint index, GLuint x, GLuint y);
	 void (APIENTRYFP glVertexAttribI3ui) (GLuint index, GLuint x, GLuint y, GLuint z);
	 void (APIENTRYFP glVertexAttribI4ui) (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	 void (APIENTRYFP glVertexAttribI1iv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttribI2iv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttribI3iv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttribI4iv) (GLuint index, const GLint *v);
	 void (APIENTRYFP glVertexAttribI1uiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttribI2uiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttribI3uiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttribI4uiv) (GLuint index, const GLuint *v);
	 void (APIENTRYFP glVertexAttribI4bv) (GLuint index, const GLbyte *v);
	 void (APIENTRYFP glVertexAttribI4sv) (GLuint index, const GLshort *v);
	 void (APIENTRYFP glVertexAttribI4ubv) (GLuint index, const GLubyte *v);
	 void (APIENTRYFP glVertexAttribI4usv) (GLuint index, const GLushort *v);
	 void (APIENTRYFP glGetUniformuiv) (GLuint program, GLint location, GLuint *params);
	 void (APIENTRYFP glBindFragDataLocation) (GLuint program, GLuint color, const GLchar *name);
	 GLint (APIENTRYFP glGetFragDataLocation) (GLuint program, const GLchar *name);
	 void (APIENTRYFP glUniform1ui) (GLint location, GLuint v0);
	 void (APIENTRYFP glUniform2ui) (GLint location, GLuint v0, GLuint v1);
	 void (APIENTRYFP glUniform3ui) (GLint location, GLuint v0, GLuint v1, GLuint v2);
	 void (APIENTRYFP glUniform4ui) (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	 void (APIENTRYFP glUniform1uiv) (GLint location, GLsizei count, const GLuint *value);
	 void (APIENTRYFP glUniform2uiv) (GLint location, GLsizei count, const GLuint *value);
	 void (APIENTRYFP glUniform3uiv) (GLint location, GLsizei count, const GLuint *value);
	 void (APIENTRYFP glUniform4uiv) (GLint location, GLsizei count, const GLuint *value);
	 void (APIENTRYFP glTexParameterIiv) (GLenum target, GLenum pname, const GLint *params);
	 void (APIENTRYFP glTexParameterIuiv) (GLenum target, GLenum pname, const GLuint *params);
	 void (APIENTRYFP glGetTexParameterIiv) (GLenum target, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetTexParameterIuiv) (GLenum target, GLenum pname, GLuint *params);
	 void (APIENTRYFP glClearBufferiv) (GLenum buffer, GLint drawbuffer, const GLint *value);
	 void (APIENTRYFP glClearBufferuiv) (GLenum buffer, GLint drawbuffer, const GLuint *value);
	 void (APIENTRYFP glClearBufferfv) (GLenum buffer, GLint drawbuffer, const GLfloat *value);
	 void (APIENTRYFP glClearBufferfi) (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	 const GLubyte *(APIENTRYFP glGetStringi) (GLenum name, GLuint index);
	 GLboolean (APIENTRYFP glIsRenderbuffer) (GLuint renderbuffer);
	 void (APIENTRYFP glBindRenderbuffer) (GLenum target, GLuint renderbuffer);
	 void (APIENTRYFP glDeleteRenderbuffers) (GLsizei n, const GLuint *renderbuffers);
	 void (APIENTRYFP glGenRenderbuffers) (GLsizei n, GLuint *renderbuffers);
	 void (APIENTRYFP glRenderbufferStorage) (GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	 void (APIENTRYFP glGetRenderbufferParameteriv) (GLenum target, GLenum pname, GLint *params);
	 GLboolean (APIENTRYFP glIsFramebuffer) (GLuint framebuffer);
	 void (APIENTRYFP glBindFramebuffer) (GLenum target, GLuint framebuffer);
	 void (APIENTRYFP glDeleteFramebuffers) (GLsizei n, const GLuint *framebuffers);
	 void (APIENTRYFP glGenFramebuffers) (GLsizei n, GLuint *framebuffers);
	 GLenum (APIENTRYFP glCheckFramebufferStatus) (GLenum target);
	 void (APIENTRYFP glFramebufferTexture1D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	 void (APIENTRYFP glFramebufferTexture2D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	 void (APIENTRYFP glFramebufferTexture3D) (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
	 void (APIENTRYFP glFramebufferRenderbuffer) (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	 void (APIENTRYFP glGetFramebufferAttachmentParameteriv) (GLenum target, GLenum attachment, GLenum pname, GLint *params);
	 void (APIENTRYFP glGenerateMipmap) (GLenum target);
	 void (APIENTRYFP glBlitFramebuffer) (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	 void (APIENTRYFP glRenderbufferStorageMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	 void (APIENTRYFP glFramebufferTextureLayer) (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	 void *(APIENTRYFP glMapBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	 void (APIENTRYFP glFlushMappedBufferRange) (GLenum target, GLintptr offset, GLsizeiptr length);
	 void (APIENTRYFP glBindVertexArray) (GLuint array);
	 void (APIENTRYFP glDeleteVertexArrays) (GLsizei n, const GLuint *arrays);
	 void (APIENTRYFP glGenVertexArrays) (GLsizei n, GLuint *arrays);
	 GLboolean (APIENTRYFP glIsVertexArray) (GLuint array);
	 void (APIENTRYFP glDrawArraysInstanced) (GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	 void (APIENTRYFP glDrawElementsInstanced) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
	 void (APIENTRYFP glTexBuffer) (GLenum target, GLenum internalformat, GLuint buffer);
	 void (APIENTRYFP glPrimitiveRestartIndex) (GLuint index);
	 void (APIENTRYFP glCopyBufferSubData) (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	 void (APIENTRYFP glGetUniformIndices) (GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
	 void (APIENTRYFP glGetActiveUniformsiv) (GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetActiveUniformName) (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
	 GLuint (APIENTRYFP glGetUniformBlockIndex) (GLuint program, const GLchar *uniformBlockName);
	 void (APIENTRYFP glGetActiveUniformBlockiv) (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetActiveUniformBlockName) (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
	 void (APIENTRYFP glUniformBlockBinding) (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	 void (APIENTRYFP glDrawElementsBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	 void (APIENTRYFP glDrawRangeElementsBaseVertex) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
	 void (APIENTRYFP glDrawElementsInstancedBaseVertex) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
	 void (APIENTRYFP glMultiDrawElementsBaseVertex) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
	 void (APIENTRYFP glProvokingVertex) (GLenum mode);
	 GLsync (APIENTRYFP glFenceSync) (GLenum condition, GLbitfield flags);
	 GLboolean (APIENTRYFP glIsSync) (GLsync sync);
	 void (APIENTRYFP glDeleteSync) (GLsync sync);
	 GLenum (APIENTRYFP glClientWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	 void (APIENTRYFP glWaitSync) (GLsync sync, GLbitfield flags, GLuint64 timeout);
	 void (APIENTRYFP glGetInteger64v) (GLenum pname, GLint64 *data);
	 void (APIENTRYFP glGetSynciv) (GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
	 void (APIENTRYFP glGetInteger64i_v) (GLenum target, GLuint index, GLint64 *data);
	 void (APIENTRYFP glGetBufferParameteri64v) (GLenum target, GLenum pname, GLint64 *params);
	 void (APIENTRYFP glFramebufferTexture) (GLenum target, GLenum attachment, GLuint texture, GLint level);
	 void (APIENTRYFP glTexImage2DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
	 void (APIENTRYFP glTexImage3DMultisample) (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
	 void (APIENTRYFP glGetMultisamplefv) (GLenum pname, GLuint index, GLfloat *val);
	 void (APIENTRYFP glSampleMaski) (GLuint maskNumber, GLbitfield mask);
	 void (APIENTRYFP glBindFragDataLocationIndexed) (GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
	 GLint (APIENTRYFP glGetFragDataIndex) (GLuint program, const GLchar *name);
	 void (APIENTRYFP glGenSamplers) (GLsizei count, GLuint *samplers);
	 void (APIENTRYFP glDeleteSamplers) (GLsizei count, const GLuint *samplers);
	 GLboolean (APIENTRYFP glIsSampler) (GLuint sampler);
	 void (APIENTRYFP glBindSampler) (GLuint unit, GLuint sampler);
	 void (APIENTRYFP glSamplerParameteri) (GLuint sampler, GLenum pname, GLint param);
	 void (APIENTRYFP glSamplerParameteriv) (GLuint sampler, GLenum pname, const GLint *param);
	 void (APIENTRYFP glSamplerParameterf) (GLuint sampler, GLenum pname, GLfloat param);
	 void (APIENTRYFP glSamplerParameterfv) (GLuint sampler, GLenum pname, const GLfloat *param);
	 void (APIENTRYFP glSamplerParameterIiv) (GLuint sampler, GLenum pname, const GLint *param);
	 void (APIENTRYFP glSamplerParameterIuiv) (GLuint sampler, GLenum pname, const GLuint *param);
	 void (APIENTRYFP glGetSamplerParameteriv) (GLuint sampler, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetSamplerParameterIiv) (GLuint sampler, GLenum pname, GLint *params);
	 void (APIENTRYFP glGetSamplerParameterfv) (GLuint sampler, GLenum pname, GLfloat *params);
	 void (APIENTRYFP glGetSamplerParameterIuiv) (GLuint sampler, GLenum pname, GLuint *params);
	 void (APIENTRYFP glQueryCounter) (GLuint id, GLenum target);
	 void (APIENTRYFP glGetQueryObjecti64v) (GLuint id, GLenum pname, GLint64 *params);
	 void (APIENTRYFP glGetQueryObjectui64v) (GLuint id, GLenum pname, GLuint64 *params);
	 void (APIENTRYFP glVertexAttribDivisor) (GLuint index, GLuint divisor);
	 void (APIENTRYFP glVertexAttribP1ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	 void (APIENTRYFP glVertexAttribP1uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	 void (APIENTRYFP glVertexAttribP2ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	 void (APIENTRYFP glVertexAttribP2uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	 void (APIENTRYFP glVertexAttribP3ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	 void (APIENTRYFP glVertexAttribP3uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
	 void (APIENTRYFP glVertexAttribP4ui) (GLuint index, GLenum type, GLboolean normalized, GLuint value);
	 void (APIENTRYFP glVertexAttribP4uiv) (GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#endif
