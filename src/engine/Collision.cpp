//
// Created by nylux on 23.03.2024.
//

#include "Collision.h"

#include "../FixtureData.h"
#include "box2d/b2_contact.h"

void Collision::BeginContact(b2Contact *contact)
{
    auto* data = reinterpret_cast<FixtureData*>(contact->GetFixtureA()->GetUserData().pointer);
    if(data && data->listener) data->listener->OnBeginContact(contact->GetFixtureB());


    data = reinterpret_cast<FixtureData*>(contact->GetFixtureB()->GetUserData().pointer);
    if(data && data->listener) data->listener->OnBeginContact(contact->GetFixtureA());
}

void Collision::EndContact(b2Contact *contact)
{
    auto* data = reinterpret_cast<FixtureData*>(contact->GetFixtureA()->GetUserData().pointer);
    if(data && data->listener) data->listener->OnEndContact(contact->GetFixtureB());


    data = reinterpret_cast<FixtureData*>(contact->GetFixtureB()->GetUserData().pointer);
    if(data && data->listener) data->listener->OnEndContact(contact->GetFixtureA());
}

void Collision::OnBeginContact(b2Fixture* other)
{

}

void Collision::OnEndContact(b2Fixture* other)
{

}
