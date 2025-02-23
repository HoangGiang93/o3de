#pragma once

/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/RTTI/RTTI.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/containers/vector.h>

namespace AZ
{
    namespace SceneAPI
    {
        namespace Containers
        {
            class SceneManifest;
        }
        namespace DataTypes
        {
            class IManifestObject
            {
            public:
                AZ_RTTI(IManifestObject, "{3B839407-1884-4FF4-ABEA-CA9D347E83F7}");
                static void Reflect(AZ::ReflectContext* context);

                virtual ~IManifestObject() = 0;
                virtual void OnUserAdded() {};
                virtual void OnUserRemoved() const {};
                // Some manifest objects cause other manifest objects to be created.
                // When those manifest objects are removed, the added manifest objects should be removed, too.
                virtual void GetManifestObjectsToRemoveOnRemoved(
                    AZStd::vector<const IManifestObject*>& /*toRemove*/, const Containers::SceneManifest& /*manifest*/) const {}
            };

            inline void IManifestObject::Reflect(AZ::ReflectContext* context)
            {
                if(AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
                {
                    serializeContext->Class<IManifestObject>()
                        ->Version(0);
                }
            }

            inline IManifestObject::~IManifestObject()
            {
            }

        }  //namespace DataTypes
    }  //namespace SceneAPI
}  //namespace AZ
