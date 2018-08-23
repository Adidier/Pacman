#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject() {

}

GameObject::~GameObject() {

}

void GameObject::GetPosition(float &x, float &y) {
	x = this->x;
	y = this->y;
}

void GameObject::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
}

int GameObject::GetPositionX() {
	return this->x;
}

void GameObject::SetPositionX(float x) {
	this->x = x;
}

int GameObject::GetPositionY() {
	return this->y;
}

void GameObject::SetPositionY(float y) {
	this->y = y;
}

void GameObject::SetType(Type t) {
	t = this->type;
}

Type GameObject::GetType() {
	return this->type;
}