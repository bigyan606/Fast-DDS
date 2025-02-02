// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file ReaderProxyData.h
 */

#ifndef _FASTDDS_RTPS_BUILTIN_DATA_READERPROXYDATA_H_
#define _FASTDDS_RTPS_BUILTIN_DATA_READERPROXYDATA_H_

#include <gmock/gmock.h>

#include <fastdds/dds/core/policy/QosPolicies.hpp>
#include <fastdds/dds/subscriber/qos/ReaderQos.hpp>
#include <fastdds/rtps/attributes/RTPSParticipantAllocationAttributes.hpp>
#include <fastdds/rtps/common/Guid.h>
#include <fastdds/rtps/common/Locator.h>
#include <fastdds/rtps/common/LocatorList.hpp>
#include <fastdds/rtps/common/RemoteLocators.hpp>
#include <fastdds/rtps/common/VendorId_t.hpp>
#if HAVE_SECURITY
#include <fastdds/rtps/security/accesscontrol/EndpointSecurityAttributes.h>
#endif // if HAVE_SECURITY

namespace eprosima {
namespace fastrtps {
namespace rtps {

class NetworkFactory;

class ReaderProxyData
{
public:

    ReaderProxyData(
            size_t max_unicast_locators,
            size_t max_multicast_locators)
        : remote_locators_(max_unicast_locators, max_multicast_locators)
        , m_expectsInlineQos(false)
        , topic_kind_(NO_KEY)
        , is_alive_(true)
        , type_info_()
        , m_userDefinedId(0)
        , content_filter_({})
    {
    }

    ReaderProxyData(
            size_t max_unicast_locators,
            size_t max_multicast_locators,
            const VariableLengthDataLimits& data_limits,
            const fastdds::rtps::ContentFilterProperty::AllocationConfiguration filter_allocation)
        : remote_locators_(max_unicast_locators, max_multicast_locators)
        , m_expectsInlineQos(false)
        , topic_kind_(NO_KEY)
        , is_alive_(true)
        , type_info_()
        , m_userDefinedId(0)
        , content_filter_(filter_allocation)
    {
        static_cast<void>(filter_allocation);

        m_qos.m_userData.set_max_size(data_limits.max_user_data);
    }

    const GUID_t& guid() const
    {
        return m_guid;
    }

    GUID_t& guid()
    {
        return m_guid;
    }

    void guid(
            const GUID_t& guid)
    {
        m_guid = guid;
    }

    bool disable_positive_acks() const
    {
        return false;
    }

    void add_unicast_locator(
            const Locator_t& locator)
    {
        remote_locators_.add_unicast_locator(locator);
    }

    void add_multicast_locator(
            const Locator_t& locator)
    {
        remote_locators_.add_multicast_locator(locator);
    }

    bool has_locators() const
    {
        return !remote_locators_.unicast.empty() || !remote_locators_.multicast.empty();
    }

    const RemoteLocatorList& remote_locators() const
    {
        return remote_locators_;
    }

    void clear ()
    {
    }

    void set_announced_unicast_locators(
            const LocatorList_t& /*locators*/)
    {
    }

    void set_remote_unicast_locators(
            const LocatorList_t& /*locators*/,
            const NetworkFactory& /*network*/)
    {
    }

    void set_remote_locators(
            const RemoteLocatorList& /*locators*/,
            const NetworkFactory& /*network*/,
            bool /*use_multicast*/)
    {
    }

    bool readFromCDRMessage(
            CDRMessage_t* /*msg*/,
            const NetworkFactory& /*network*/,
            bool /*is_shm_transport_possible*/,
            fastdds::rtps::VendorId_t /*source_vendor_id*/)
    {
        return true;
    }

    void set_multicast_locators(
            const LocatorList_t& /*locator*/,
            const NetworkFactory& /*network*/)
    {
    }

    void typeName(
            const fastcdr::string_255& typeName)
    {
        type_name_ = typeName;
    }

    const fastcdr::string_255& typeName() const
    {
        return type_name_;
    }

    fastcdr::string_255& typeName()
    {
        return type_name_;
    }

    void topicName(
            const fastcdr::string_255& topicName)
    {
        topic_name_ = topicName;
    }

    const fastcdr::string_255& topicName() const
    {
        return topic_name_;
    }

    fastcdr::string_255& topicName()
    {
        return topic_name_;
    }

    void topicKind(
            TopicKind_t topicKind)
    {
        topic_kind_ = topicKind;
    }

    TopicKind_t topicKind() const
    {
        return topic_kind_;
    }

    TopicKind_t& topicKind()
    {
        return topic_kind_;
    }

    void isAlive (
            bool alive)
    {
        is_alive_ = alive;
    }

    bool isAlive () const
    {
        return is_alive_;
    }

    bool has_type_information () const
    {
        return false;
    }

    void type_information(
            const fastdds::dds::xtypes::TypeInformationParameter& other_type_info)
    {
        type_info_ = other_type_info;
    }

    const fastdds::dds::xtypes::TypeInformationParameter& type_information() const
    {
        return type_info_;
    }

    fastdds::dds::xtypes::TypeInformationParameter& type_information()
    {
        return type_info_;
    }

    void key(
            const InstanceHandle_t& key)
    {
        m_key = key;
    }

    void key(
            InstanceHandle_t&& key)
    {
        m_key = std::move(key);
    }

    InstanceHandle_t key() const
    {
        return m_key;
    }

    InstanceHandle_t& key()
    {
        return m_key;
    }

    void RTPSParticipantKey(
            const InstanceHandle_t& RTPSParticipantKey)
    {
        m_RTPSParticipantKey = RTPSParticipantKey;
    }

    void RTPSParticipantKey(
            InstanceHandle_t&& RTPSParticipantKey)
    {
        m_RTPSParticipantKey = std::move(RTPSParticipantKey);
    }

    InstanceHandle_t RTPSParticipantKey() const
    {
        return m_RTPSParticipantKey;
    }

    InstanceHandle_t& RTPSParticipantKey()
    {
        return m_RTPSParticipantKey;
    }

    void set_locators(
            const RemoteLocatorList& /*locators*/)
    {

    }

    void userDefinedId(
            uint16_t userDefinedId)
    {
        m_userDefinedId = userDefinedId;
    }

    uint16_t userDefinedId() const
    {
        return m_userDefinedId;
    }

    uint16_t& userDefinedId()
    {
        return m_userDefinedId;
    }

    FASTDDS_EXPORTED_API void content_filter(
            const fastdds::rtps::ContentFilterProperty& filter)
    {
        content_filter_ = filter;
    }

    FASTDDS_EXPORTED_API void content_filter(
            fastdds::rtps::ContentFilterProperty&& filter)
    {
        content_filter_ = std::move(filter);
    }

    FASTDDS_EXPORTED_API const fastdds::rtps::ContentFilterProperty& content_filter() const
    {
        return content_filter_;
    }

    FASTDDS_EXPORTED_API fastdds::rtps::ContentFilterProperty& content_filter()
    {
        return content_filter_;
    }

    void copy(
            ReaderProxyData* /*rdat*/)
    {

    }

#if HAVE_SECURITY
    security::EndpointSecurityAttributesMask security_attributes_ = 0UL;
    security::PluginEndpointSecurityAttributesMask plugin_security_attributes_ = 0UL;
#endif // if HAVE_SECURITY

    RemoteLocatorList remote_locators_;
    bool m_expectsInlineQos;
    fastdds::dds::ReaderQos m_qos;

private:

    GUID_t m_guid;
    fastcdr::string_255 topic_name_;
    fastcdr::string_255 type_name_;
    TopicKind_t topic_kind_;
    bool is_alive_;
    fastdds::dds::xtypes::TypeInformationParameter type_info_;
    InstanceHandle_t m_key;
    InstanceHandle_t m_RTPSParticipantKey;
    uint16_t m_userDefinedId;
    fastdds::rtps::ContentFilterProperty content_filter_;

};

} // namespace rtps
} // namespace fastrtps
} // namespace eprosima

#endif // _FASTDDS_RTPS_BUILTIN_DATA_READERPROXYDATA_H_
