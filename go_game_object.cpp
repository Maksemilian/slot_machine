#include "go_game_object.h"


GameObject::GameObject(Renderable* renderable)
    : _renderable(renderable) {}

GameObject::~GameObject() {}

void GameObject::onPressEvent(int x, int y)
{
    UNUSED(x);
    UNUSED(y);
}
