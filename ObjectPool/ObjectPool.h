#pragma once
#include<vector>
#include<iostream>

template <class T>
class Object
{
private:
	bool isActive;
	T *pObject;
public:
	Object()
	{
		isActive = false;
		pObject = NULL;
	}
	~Object()
	{
		if (pObject != NULL)
		{
			delete pObject;
		}		
	}

	void SetActive(bool b)
	{
		isActive = b;
	}

	void SetObject(T *pOjt)
	{
		pObject = pOjt;
	}

	bool GetActive()
	{
		return isActive;
	}

	T *GetObject()
	{
		return pObject;
	}
};

template<class T>
class ObjectPool
{
private:
	std::vector<Object<T>*> pooledObjects;
	int amountPool;

public:
	ObjectPool(int size)
	{
		amountPool = size;

		for (int i = 0; i < amountPool; i++)
		{
			Object<T> *pObj = new Object<T>;
			pObj->SetActive(false);
			pObj->SetObject(new T);
			pooledObjects.push_back(pObj);
		}
	}
	~ObjectPool()
	{
		for (int i = 0; i < amountPool; i++)
		{
			delete pooledObjects[i];
		}
	}

	Object<T> *GetPooledObject()
	{
		for (int i = 0; i < amountPool; i++)
		{
			if (!pooledObjects[i]->GetActive())
			{
				return pooledObjects[i];
			}
		}
		return NULL;
	}
};

class Ball
{
private:
public:
	int val = 0;

	bool Collision(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
	{
		if (x1 <= x4 && x2 >= x3 && y1 <= y4 && y2 >= y3)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
