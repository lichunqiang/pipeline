
extern zend_class_entry *pipeline_defaultprocessor_ce;

ZEPHIR_INIT_CLASS(Pipeline_DefaultProcessor);

PHP_METHOD(Pipeline_DefaultProcessor, process);
void zep_Pipeline_DefaultProcessor_process_zephir_internal_call(int ht, zval *return_value, zval *this_ptr, int return_value_used, zval *stages_param_ext, zval *playload_ext );

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_defaultprocessor_process, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, stages, 0)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_defaultprocessor_process_zephir_internal_call, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, stages, 0)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pipeline_defaultprocessor_method_entry) {
	PHP_ME(Pipeline_DefaultProcessor, process, arginfo_pipeline_defaultprocessor_process, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
