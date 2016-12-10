
extern zend_class_entry *pipeline_processorinterface_ce;

ZEPHIR_INIT_CLASS(Pipeline_ProcessorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_processorinterface_process, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, stages, 0)
	ZEND_ARG_INFO(0, playload)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pipeline_processorinterface_method_entry) {
	PHP_ABSTRACT_ME(Pipeline_ProcessorInterface, process, arginfo_pipeline_processorinterface_process)
	PHP_FE_END
};
