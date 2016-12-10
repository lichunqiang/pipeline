
extern zend_class_entry *pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Pipeline_Pipeline);

PHP_METHOD(Pipeline_Pipeline, __construct);
PHP_METHOD(Pipeline_Pipeline, pipe);
PHP_METHOD(Pipeline_Pipeline, process);
PHP_METHOD(Pipeline_Pipeline, __invoke);
PHP_METHOD(Pipeline_Pipeline, getStages);
PHP_METHOD(Pipeline_Pipeline, getProcessor);
void zep_Pipeline_Pipeline_pipe_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *opertaion_ext );
void zep_Pipeline_Pipeline_process_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *playload_ext );
void zep_Pipeline_Pipeline_getStages_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used);
void zep_Pipeline_Pipeline_getProcessor_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used);
zend_object *zephir_init_properties_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, stages, 1)
	ZEND_ARG_OBJ_INFO(0, processor, Pipeline\\ProcessorInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline_pipe, 0, 0, 1)
	ZEND_ARG_INFO(0, opertaion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline_process, 0, 0, 1)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline_pipe_zephir_internal_call, 0, 0, 1)
	ZEND_ARG_INFO(0, opertaion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipeline_process_zephir_internal_call, 0, 0, 1)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pipeline_pipeline_method_entry) {
	PHP_ME(Pipeline_Pipeline, __construct, arginfo_pipeline_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Pipeline_Pipeline, pipe, arginfo_pipeline_pipeline_pipe, ZEND_ACC_PUBLIC)
	PHP_ME(Pipeline_Pipeline, process, arginfo_pipeline_pipeline_process, ZEND_ACC_PUBLIC)
	PHP_ME(Pipeline_Pipeline, __invoke, arginfo_pipeline_pipeline___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Pipeline_Pipeline, getStages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Pipeline_Pipeline, getProcessor, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
