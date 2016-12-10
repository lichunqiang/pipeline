
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Pipeline_ProcessorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pipeline, ProcessorInterface, pipeline, processorinterface, pipeline_processorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Pipeline_ProcessorInterface, process);

