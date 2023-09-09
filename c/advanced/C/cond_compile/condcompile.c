#include <stdio.h>
/*
 * 根据宏是否定义，其语法如下：
 * #ifdef  <macro>
 *		  ……
 *		#else
 * 		 ……
 *		#endif
 * */
#define _DEBUG_

int main(void) {
#ifdef _DEBUG_
    printf("The macro _DEBUG_ is defined\n");
#else
    printf("The macro _DEBUG_ is not defined\n");
#endif
}
