
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Pipeline_Pipeline) {

	ZEPHIR_REGISTER_CLASS(Pipeline, Pipeline, pipeline, pipeline, pipeline_pipeline_method_entry, 0);

	/**
	 * @var array stages Process stages.
	 */
	zend_declare_property_null(pipeline_pipeline_ce, SL("stages"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var ProcessorInterface processor
	 */
	zend_declare_property_null(pipeline_pipeline_ce, SL("processor"), ZEND_ACC_PRIVATE TSRMLS_CC);

	pipeline_pipeline_ce->create_object = zephir_init_properties_Pipeline_Pipeline;

	zend_class_implements(pipeline_pipeline_ce TSRMLS_CC, 1, pipeline_pipelineinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Pipeline_Pipeline, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *stages_param = NULL, *processor = NULL, processor_sub, __$null, stage, *_0, _1;
	zval stages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&stages);
	ZVAL_UNDEF(&processor_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &stages_param, &processor);

	if (!stages_param) {
		ZEPHIR_INIT_VAR(&stages);
		array_init(&stages);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&stages, stages_param);
	}
	if (!processor) {
		processor = &processor_sub;
		processor = &__$null;
	}


	ZEPHIR_CHECK_POINTER(stages);
	zephir_is_iterable(&stages, 0, "pipeline/pipeline.zep", 23);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&stages), _0)
	{
		ZEPHIR_INIT_NVAR(&stage);
		ZVAL_COPY(&stage, _0);
		ZEPHIR_CHECK_POINTER(stage);
		if (0 == zephir_is_callable(&stage TSRMLS_CC)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "All stages should be callable.", "pipeline/pipeline.zep", 19);
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&stage);
	ZEPHIR_CHECK_POINTER(stages);
	zephir_update_property_zval(this_ptr, SL("stages"), &stages);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CHECK_POINTER(processor);
	if (zephir_is_true(processor)) {
		ZEPHIR_CHECK_POINTER(processor);
		ZEPHIR_CPY_WRT(&_1, processor);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		object_init_ex(&_1, pipeline_defaultprocessor_ce);
		if (zephir_has_constructor(&_1 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, SL("processor"), &_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Pipeline_Pipeline, pipe) {

	zval *opertaion = NULL, opertaion_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&opertaion_sub);

	zephir_fetch_params(0, 1, 0, &opertaion);



	ZEPHIR_CHECK_POINTER(opertaion);
	zephir_update_property_array_append(this_ptr, SL("stages"), opertaion TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @param  mixed playload
 * @return mixed
 */
PHP_METHOD(Pipeline_Pipeline, process) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *playload = NULL, playload_sub, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&playload_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &playload);



	zephir_read_property(&_0, this_ptr, SL("processor"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("stages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CHECK_POINTER(playload);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "process", NULL, 0, &_1, playload);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param  mixed playload
 * @return mixed
 */
PHP_METHOD(Pipeline_Pipeline, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *playload = NULL, playload_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&playload_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &playload);



	ZEPHIR_CHECK_POINTER(playload);
	ZEPHIR_RETURN_CALL_INTERNAL_METHOD_P1(this_ptr, zep_Pipeline_Pipeline_process_zephir_internal_call, playload);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Pipeline_Pipeline, getStages) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "stages");

}

PHP_METHOD(Pipeline_Pipeline, getProcessor) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "processor");

}

void zep_Pipeline_Pipeline_pipe_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *opertaion_ext ) {

	zval *opertaion = NULL, opertaion_sub;
		ZVAL_UNDEF(&opertaion_sub);

	ZEPHIR_CHECK_POINTER(opertaion);
opertaion = opertaion_ext;




	ZEPHIR_CHECK_POINTER(opertaion);
	zephir_update_property_array_append(this_ptr, SL("stages"), opertaion TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @param  mixed playload
 * @return mixed
 */
void zep_Pipeline_Pipeline_process_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *playload_ext ) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *playload = NULL, playload_sub, _0, _1;
		ZVAL_UNDEF(&playload_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	ZEPHIR_CHECK_POINTER(playload);
playload = playload_ext;




	zephir_read_property(&_0, this_ptr, SL("processor"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("stages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CHECK_POINTER(playload);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "process", NULL, 0, &_1, playload);
	zephir_check_call_status();
	RETURN_MM();

}

void zep_Pipeline_Pipeline_getStages_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used) {

	

	RETURN_MEMBER(this_ptr, "stages");

}

void zep_Pipeline_Pipeline_getProcessor_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used) {

	

	RETURN_MEMBER(this_ptr, "processor");

}

zend_object *zephir_init_properties_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("stages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("stages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

