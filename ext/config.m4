PHP_ARG_ENABLE(pipeline, whether to enable pipeline, [ --enable-pipeline   Enable Pipeline])

if test "$PHP_PIPELINE" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PIPELINE_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PIPELINE, 1, [Whether you have Pipeline])
	pipeline_sources="pipeline.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c pipeline/pipelineinterface.zep.c
	pipeline/processorinterface.zep.c
	pipeline/defaultprocessor.zep.c
	pipeline/pipeline.zep.c
	pipeline/stageinterface.zep.c "
	PHP_NEW_EXTENSION(pipeline, $pipeline_sources, $ext_shared,, )
	PHP_SUBST(PIPELINE_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([pipeline], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([pipeline], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/pipeline], [php_PIPELINE.h])

fi
