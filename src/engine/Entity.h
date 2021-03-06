/**************************************************************************************************
 * Title:         Entity.h
 * Author:        Omar Stefan Evans
 * Created on:    2014-09-14
 * Description:   <#Description#>
 * Purpose:       <#Purpose#>
 * Modifications: <#Modifications#>
 **************************************************************************************************/

#pragma once

#include "numerical_types.h"

namespace evansbros {
    namespace game {
        class Entity {
            friend class EntityManager;
        public:
            Entity() = default;
            Entity(UniqueID uid) : uid(uid) {}
            UniqueID getUID() const { return uid; }
        private:
            UniqueID uid = 0;
        };
    }
}