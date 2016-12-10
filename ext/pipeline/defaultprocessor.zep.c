
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Pipeline_DefaultProcessor) {

	ZEPHIR_REGISTER_CLASS(Pipeline, DefaultProcessor, pipeline, defaultprocessor, pipeline_defaultprocessor_method_entry, 0);

	zend_class_implements(pipeline_defaultprocessor_ce TSRMLS_CC, 1, pipeline_processorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Pipeline_DefaultProcessor, process) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *stages_param = NULL, *playload = NULL, playload_sub, stage, *_0, _1$$3;
	zval stages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&stages);
	ZVAL_UNDEF(&playload_sub);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &stages_param, &playload);

	ZEPHIR_OBS_COPY_OR_DUP(&stages, stages_param);
	ZEPHIR_SEPARATE_PARAM(playload);


	ZEPHIR_CHECK_POINTER(stages);
	zephir_is_iterable(&stages, 0, "pipeline/defaultprocessor.zep", 12);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&stages), _0)
	{
		ZEPHIR_INIT_NVAR(&stage);
		ZVAL_COPY(&stage, _0);
		ZEPHIR_CHECK_POINTER(stage);
		ZEPHIR_CHECK_POINTER(playload);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_1$$3, &stage, NULL, 0, playload);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(playload, &_1$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&stage);
	ZEPHIR_CHECK_POINTER(playload);
	RETVAL_ZVAL(playload, 1, 0);
	RETURN_MM();

}

void zep_Pipeline_DefaultProcessor_process_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *stages_param_ext, zval *playload_ext ) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *stages_param = NULL, *playload = NULL, playload_sub, stage, *_0, _1$$3;
	zval stages;
		ZVAL_UNDEF(&stages);
	ZVAL_UNDEF(&playload_sub);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	ZEPHIR_CHECK_POINTER(stages_param);
stages_param = stages_param_ext;

	ZEPHIR_CHECK_POINTER(playload);
playload = playload_ext;


	ZEPHIR_OBS_COPY_OR_DUP(&stages, stages_param);
	ZEPHIR_SEPARATE_PARAM(playload);


	ZEPHIR_CHECK_POINTER(stages);
	zephir_is_iterable(&stages, 0, "pipeline/defaultprocessor.zep", 12);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&stages), _0)
	{
		ZEPHIR_INIT_NVAR(&stage);
		ZVAL_COPY(&stage, _0);
		ZEPHIR_CHECK_POINTER(stage);
		ZEPHIR_CHECK_POINTER(playload);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_1$$3, &stage, NULL, 0, playload);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(playload, &_1$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&stage);
	ZEPHIR_CHECK_POINTER(playload);
	RETVAL_ZVAL(playload, 1, 0);
	RETURN_MM();

}

