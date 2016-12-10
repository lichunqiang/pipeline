
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * The stage interface.
 */
ZEPHIR_INIT_CLASS(Pipeline_StageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Pipeline, StageInterface, pipeline, stageinterface, pipeline_stageinterface_method_entry);

	return SUCCESS;

}

/**
 * @param  mixed playload
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Pipeline_StageInterface, __invoke);

