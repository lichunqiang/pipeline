
extern zend_class_entry *pipeline_stageinterface_ce;

ZEPHIR_INIT_CLASS(Pipeline_StageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pipeline_stageinterface___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, payload)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pipeline_stageinterface_method_entry) {
	PHP_ABSTRACT_ME(Pipeline_StageInterface, __invoke, arginfo_pipeline_stageinterface___invoke)
	PHP_FE_END
};
