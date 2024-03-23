//
// Created by nylux on 23.03.2024.
//

#include "Collision.h"

#include "box2d/b2_contact.h"

void Collision::BeginContact(b2Contact *contact)
{
    auto* collision  = reinterpret_cast<Collision*>(contact->GetFixtureA()->GetUserData().pointer);
    if(collision) collision -> OnBeginContact();


    collision  = reinterpret_cast<Collision*>(contact->GetFixtureB()->GetUserData().pointer);
    if(collision) collision -> OnBeginContact();
}

void Collision::EndContact(b2Contact *contact)
{
    auto* collision  = reinterpret_cast<Collision*>(contact->GetFixtureA()->GetUserData().pointer);
    if(collision) collision -> OnEndContact();


    collision  = reinterpret_cast<Collision*>(contact->GetFixtureB()->GetUserData().pointer);
    if(collision) collision -> OnEndContact();
}

void Collision::OnBeginContact()
{

}

void Collision::OnEndContact()
{

}
