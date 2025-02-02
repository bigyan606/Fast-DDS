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

/*!
 * @file basic_inner_typesCdrAux.ipp
 * This source file contains some declarations of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_BASIC_INNER_TYPESCDRAUX_IPP_
#define _FAST_DDS_GENERATED_BASIC_INNER_TYPESCDRAUX_IPP_

#include "basic_inner_typesCdrAux.hpp"

#include <fastcdr/Cdr.h>
#include <fastcdr/CdrSizeCalculator.hpp>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

namespace eprosima {
namespace fastcdr {

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const InnerStructureHelper& data,
        size_t& current_alignment)
{
    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};


        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0),
                data.field1(), current_alignment);

        calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                data.field2(), current_alignment);


    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const InnerStructureHelper& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr
        << eprosima::fastcdr::MemberId(0) << data.field1()
        << eprosima::fastcdr::MemberId(1) << data.field2()
;
    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        InnerStructureHelper& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                switch (mid.id)
                {
                                        case 0:
                                                dcdr >> data.field1();
                                            break;

                                        case 1:
                                                dcdr >> data.field2();
                                            break;

                    default:
                        ret_value = false;
                        break;
                }
                return ret_value;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const InnerStructureHelper& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
}


template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const InnerEmptyStructureHelper& data,
        size_t& current_alignment)
{
    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};



    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const InnerEmptyStructureHelper& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    static_cast<void>(data);

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        InnerEmptyStructureHelper& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                static_cast<void>(data);
                static_cast<void>(dcdr);
                static_cast<void>(mid);
                return false;
            });
}

void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const InnerEmptyStructureHelper& data)
{
    static_cast<void>(scdr);
    static_cast<void>(data);
}


template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const InnerUnionHelper& data,
        size_t& current_alignment)
{
    static_cast<void>(data);

    eprosima::fastcdr::EncodingAlgorithmFlag previous_encoding = calculator.get_encoding();
    size_t calculated_size {calculator.begin_calculate_type_serialized_size(
                                eprosima::fastcdr::CdrVersion::XCDRv2 == calculator.get_cdr_version() ?
                                eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
                                eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
                                current_alignment)};

    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(0), data._d(),
                    current_alignment);

    switch (data._d())
    {
                case 0:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(1),
                                data.longValue(), current_alignment);
                    break;

                case 1:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(2),
                                data.floatValue(), current_alignment);
                    break;

                default:
                    calculated_size += calculator.calculate_member_serialized_size(eprosima::fastcdr::MemberId(3),
                                data.shortValue(), current_alignment);
                    break;

    }

    calculated_size += calculator.end_calculate_type_serialized_size(previous_encoding, current_alignment);

    return calculated_size;
}


template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const InnerUnionHelper& data)
{
    eprosima::fastcdr::Cdr::state current_state(scdr);
    scdr.begin_serialize_type(current_state,
            eprosima::fastcdr::CdrVersion::XCDRv2 == scdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR);

    scdr << eprosima::fastcdr::MemberId(0) << data._d();

    switch (data._d())
    {
                case 0:
                    scdr << eprosima::fastcdr::MemberId(1) << data.longValue();
                    break;

                case 1:
                    scdr << eprosima::fastcdr::MemberId(2) << data.floatValue();
                    break;

                default:
                    scdr << eprosima::fastcdr::MemberId(3) << data.shortValue();
                    break;

    }

    scdr.end_serialize_type(current_state);
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& cdr,
        InnerUnionHelper& data)
{
    cdr.deserialize_type(eprosima::fastcdr::CdrVersion::XCDRv2 == cdr.get_cdr_version() ?
            eprosima::fastcdr::EncodingAlgorithmFlag::DELIMIT_CDR2 :
            eprosima::fastcdr::EncodingAlgorithmFlag::PLAIN_CDR,
            [&data](eprosima::fastcdr::Cdr& dcdr, const eprosima::fastcdr::MemberId& mid) -> bool
            {
                bool ret_value = true;
                if (0 == mid.id)
                {
                    int32_t discriminator;
                    dcdr >> discriminator;

                    switch (discriminator)
                    {
                                                case 0:
                                                    {
                                                        int32_t longValue_value{0};
                                                        data.longValue(std::move(longValue_value));
                                                        data._d(discriminator);
                                                        break;
                                                    }

                                                case 1:
                                                    {
                                                        float floatValue_value{0.0};
                                                        data.floatValue(std::move(floatValue_value));
                                                        data._d(discriminator);
                                                        break;
                                                    }

                                                default:
                                                    {
                                                        int16_t shortValue_value{0};
                                                        data.shortValue(std::move(shortValue_value));
                                                        data._d(discriminator);
                                                        break;
                                                    }

                    }
                }
                else
                {
                    switch (data._d())
                    {
                                                case 0:
                                                    dcdr >> data.longValue();
                                                    break;

                                                case 1:
                                                    dcdr >> data.floatValue();
                                                    break;

                                                default:
                                                    dcdr >> data.shortValue();
                                                    break;

                    }
                    ret_value = false;
                }
                return ret_value;
            });
}

template<>
eProsima_user_DllExport size_t calculate_serialized_size(
        eprosima::fastcdr::CdrSizeCalculator& calculator,
        const InnerBitsetHelper& data,
        size_t& current_alignment)
{
    return calculator.calculate_serialized_size(data.bitset(), current_alignment);
}

template<>
eProsima_user_DllExport void serialize(
        eprosima::fastcdr::Cdr& scdr,
        const InnerBitsetHelper& data)
{
    scdr << data.bitset();
}

template<>
eProsima_user_DllExport void deserialize(
        eprosima::fastcdr::Cdr& dcdr,
        InnerBitsetHelper& data)
{
    std::bitset<33> bitset;
    dcdr >> bitset;
    data.bitset(bitset);
}












} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_BASIC_INNER_TYPESCDRAUX_IPP_

