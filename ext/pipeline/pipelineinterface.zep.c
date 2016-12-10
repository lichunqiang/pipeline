
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Pipeline_PipelineInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pipeline, PipelineInterface, pipeline, pipelineinterface, pipeline_pipelineinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Pipeline_PipelineInterface, pipe);

