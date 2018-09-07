#pragma once

enum Type {
	wall,
	pellet,
	ghost,
	cherry,
	pacman,
	superPellet
};

class GameObject
{
protected:
	float x, y;
	float rotation{ 0 };
	Type type;
public:
	void GetPosition(float &x, float &y);
	void SetPosition(float x, float y);
	void SetType(Type t);
	Type GetType();
	GameObject();
	~GameObject();
	int GetPositionX();
	void SetPositionX(float x);
	int GetPositionY();
	void SetPositionY(float y);
};