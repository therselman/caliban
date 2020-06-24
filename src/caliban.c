#include <assert.h>
#include <node_api.h>
//#include "caliban.h"

napi_value Method(napi_env env, napi_callback_info info)
{
	napi_status status;

	napi_value world;
	status = napi_create_string_utf8(env, "world", 5, &world);
	assert(status == napi_ok);

	return world;
}

#define DECLARE_NAPI_METHOD(name, func)				\
	{ name, 0, func, 0, 0, 0, napi_default, 0 }

napi_value init(napi_env env, napi_value exports)
{
	napi_status status;

	napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Method);

	status = napi_define_properties(env, exports, 1, &desc);
	assert(status == napi_ok);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)

/*
#define NAPI_CALL(env, call)												\
	do {																	\
		napi_status status = (call);										\
		if (status != napi_ok) {											\
			const napi_extended_error_info* error_info = NULL;				\
			napi_get_last_error_info((env), &error_info);					\
			bool is_pending;												\
			napi_is_exception_pending((env), &is_pending);					\
			if (!is_pending) {												\
				const char* message = (error_info->error_message == NULL)	\
					? "empty error message"									\
					: error_info->error_message;							\
				napi_throw_error((env), NULL, message);						\
				return NULL;												\
			}																\
		}																	\
	} while(0)

static napi_value DoSomethingUseful(napi_env env, napi_callback_info info)
{
	// Do something useful.
	return NULL;
}

napi_value create_addon(napi_env env)
{
	napi_value result;
	NAPI_CALL(env, napi_create_object(env, &result));

	napi_value exported_function;
	NAPI_CALL(env, napi_create_function(env, "doSomethingUseful", NAPI_AUTO_LENGTH, DoSomethingUseful, NULL, &exported_function));

	NAPI_CALL(env, napi_set_named_property(env, result, "doSomethingUseful", exported_function));

	return result;
}
*/
