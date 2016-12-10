
extern zend_class_entry *pipeline_pipelineinterface_ce;

ZEPHIR_INIT_CLASS(Pipeline_PipelineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_pipelineinterface_pipe, 0, 0, 1)
	ZEND_ARG_INFO(0, operation)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pipeline_pipelineinterface_method_entry) {
	PHP_ABSTRACT_ME(Pipeline_PipelineInterface, pipe, arginfo_pipeline_pipelineinterface_pipe)
	PHP_FE_END
};
