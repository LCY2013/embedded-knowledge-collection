#include <stdio.h>
/*
 * 根据宏是否定义，其语法如下：
 * #if  <macro>
 *		  ……
 *		#else
 * 		 ……
 *		#endif
 * */
#define _DEBUG_ 0

int main(void) {
#if _DEBUG_
    printf("The macro _DEBUG_ is defined\n");
#else
    printf("The macro _DEBUG_ is not defined\n");
#endif
}
