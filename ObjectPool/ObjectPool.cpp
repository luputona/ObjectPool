#include "ObjectPool.h"


void main()
{
	ObjectPool<Ball > pool(50);
	Object<Ball> *pPooledObj = pool.GetPooledObject();

	Ball *pObj = pPooledObj->GetObject();
	pObj->val;

	std::cout << pObj->val << std::endl;

}
