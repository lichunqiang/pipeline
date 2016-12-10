
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_PIPELINE_H
#define PHP_PIPELINE_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_PIPELINE_NAME        "pipeline"
#define PHP_PIPELINE_VERSION     "0.0.1"
#define PHP_PIPELINE_EXTNAME     "pipeline"
#define PHP_PIPELINE_AUTHOR      "lichunqiang<light-li@hotmail.com>"
#define PHP_PIPELINE_ZEPVERSION  "0.9.5a-dev-bad1ef6b4d"
#define PHP_PIPELINE_DESCRIPTION "Pipeline tool kit."



ZEND_BEGIN_MODULE_GLOBALS(pipeline)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(pipeline)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(pipeline)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(pipeline, v)
#else
	#define ZEPHIR_GLOBAL(v) (pipeline_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_pipeline_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(pipeline_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(pipeline_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def pipeline_globals
#define zend_zephir_globals_def zend_pipeline_globals

extern zend_module_entry pipeline_module_entry;
#define phpext_pipeline_ptr &pipeline_module_entry

#endif
