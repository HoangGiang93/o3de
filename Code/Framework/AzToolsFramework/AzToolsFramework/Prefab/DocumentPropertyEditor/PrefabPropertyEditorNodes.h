/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzFramework/DocumentPropertyEditor/DocumentSchema.h>

namespace AzToolsFramework::Prefab::PrefabPropertyEditorNodes
{
    struct PrefabOverrideLabel : AZ::DocumentPropertyEditor::NodeDefinition
    {
        static constexpr AZStd::string_view Name = "PrefabOverrideLabel";
        static constexpr auto Text = AZ::DocumentPropertyEditor::AttributeDefinition<AZStd::string_view>("Text");
        static constexpr auto IsOverridden = AZ::DocumentPropertyEditor::AttributeDefinition<bool>("IsOverridden");
    };
} // namespace AzToolsFramework::Prefab::PrefabPropertyEditorNodes
