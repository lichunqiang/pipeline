#ifndef ZEPHIR_KERNEL_FCALL_INTERNAL_H
#define ZEPHIR_KERNEL_FCALL_INTERNAL_H
	#define ZEPHIR_RETURN_CALL_INTERNAL_METHOD_P1(object, method, p0) \
		do { \
			ZEPHIR_BACKUP_SCOPE(); \
			ZEPHIR_BACKUP_THIS_PTR(); \
			ZEPHIR_SET_THIS(object); \
			ZEPHIR_SET_SCOPE((Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL), (Z_OBJ_P(object) ? Z_OBJCE_P(object) : NULL)); \
			zval _p0; \
			ZVAL_COPY(&_p0, p0); \
			method(0, return_value, object, 0, &_p0); \
			Z_TRY_DELREF_P(p0); \
			ZEPHIR_LAST_CALL_STATUS = EG(exception) ? FAILURE : SUCCESS; \
			ZEPHIR_RESTORE_THIS_PTR(); \
			ZEPHIR_RESTORE_SCOPE(); \
		} while (0)
	
#endif
