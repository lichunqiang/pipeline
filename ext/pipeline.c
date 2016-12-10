
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "pipeline.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *pipeline_pipelineinterface_ce;
zend_class_entry *pipeline_processorinterface_ce;
zend_class_entry *pipeline_stageinterface_ce;
zend_class_entry *pipeline_defaultprocessor_ce;
zend_class_entry *pipeline_pipeline_ce;

ZEND_DECLARE_MODULE_GLOBALS(pipeline)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(pipeline)
{
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Pipeline_PipelineInterface);
	ZEPHIR_INIT(Pipeline_ProcessorInterface);
	ZEPHIR_INIT(Pipeline_StageInterface);
	ZEPHIR_INIT(Pipeline_DefaultProcessor);
	ZEPHIR_INIT(Pipeline_Pipeline);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(pipeline)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_pipeline_globals *pipeline_globals TSRMLS_DC)
{
	pipeline_globals->initialized = 0;

	/* Memory options */
	pipeline_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	pipeline_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	pipeline_globals->cache_enabled = 1;

	/* Recursive Lock */
	pipeline_globals->recursive_lock = 0;

	/* Static cache */
	memset(pipeline_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_pipeline_globals *pipeline_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(pipeline)
{

	zend_pipeline_globals *pipeline_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	pipeline_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(pipeline_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(pipeline_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(pipeline)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(pipeline)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PIPELINE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PIPELINE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PIPELINE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PIPELINE_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PIPELINE_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(pipeline)
{
	php_zephir_init_globals(pipeline_globals TSRMLS_CC);
	php_zephir_init_module_globals(pipeline_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(pipeline)
{

}


zend_function_entry php_pipeline_functions[] = {
ZEND_FE_END

};

zend_module_entry pipeline_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_PIPELINE_EXTNAME,
	php_pipeline_functions,
	PHP_MINIT(pipeline),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(pipeline),
#else
	NULL,
#endif
	PHP_RINIT(pipeline),
	PHP_RSHUTDOWN(pipeline),
	PHP_MINFO(pipeline),
	PHP_PIPELINE_VERSION,
	ZEND_MODULE_GLOBALS(pipeline),
	PHP_GINIT(pipeline),
	PHP_GSHUTDOWN(pipeline),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_PIPELINE
ZEND_GET_MODULE(pipeline)
#endif
