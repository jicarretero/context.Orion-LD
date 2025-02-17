/*
*
* Copyright 2013 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Ken Zangelin
*/
#include "gtest/gtest.h"

#include "logMsg/logMsg.h"
#include "logMsg/traceLevels.h"
#include "common/statistics.h"
#include "orionld/types/OrionldMimeType.h"



/* ****************************************************************************
*
* statisticsUpdate -
*
*/
TEST(commonStatistics, statisticsUpdate)
{
  noOfDiscoveries                            = 0;
  noOfAvailabilitySubscriptionUpdates        = 0;
  noOfAvailabilityNotificationsReceived      = 0;
  noOfUpdates                                = 0;
  noOfSubscriptions                          = 0;
  noOfUnsubscriptions                        = 0;

  noOfContextEntityAttributes                = 0;
  noOfIndividualContextEntity                = 0;
  noOfIndividualContextEntityAttribute       = 0;
  noOfUpdateContextElement                   = 0;
  noOfUpdateContextAttribute                 = 0;
  noOfNgsi10ContextEntityTypesAttributeContainer = 0;
  noOfNgsi10SubscriptionsConvOp              = 0;
  noOfVersionRequests                        = 0;
  noOfLeakRequests                           = 0;
  noOfInvalidRequests                        = 0;
  noOfJsonRequests                           = 0;

  noOfRtSubscribeContextAvailabilityResponse          = 0;
  noOfRtUnsubscribeContextAvailabilityResponse        = 0;
  noOfRtSubscribeResponse                             = 0;

  statisticsUpdate(DiscoverContextAvailability, MT_JSON);
  statisticsUpdate(UpdateContextAvailabilitySubscription, MT_JSON);
  statisticsUpdate(NotifyContextAvailability, MT_JSON);
  statisticsUpdate(SubscribeContext, MT_JSON);
  statisticsUpdate(UnsubscribeContext, MT_JSON);
  statisticsUpdate(UpdateContext, MT_JSON);
  statisticsUpdate(RtQueryContextResponse, MT_JSON);

  statisticsUpdate(ContextEntityAttributes, MT_JSON);
  statisticsUpdate(IndividualContextEntity, MT_JSON);
  statisticsUpdate(AttributeValueInstance, MT_JSON);
  statisticsUpdate(IndividualContextEntityAttribute, MT_JSON);
  statisticsUpdate(UpdateContextElement, MT_JSON);
  statisticsUpdate(UpdateContextAttribute, MT_JSON);
  statisticsUpdate(Ngsi10ContextEntityTypesAttributeContainer, MT_JSON);
  statisticsUpdate(Ngsi10SubscriptionsConvOp, MT_JSON);
  statisticsUpdate(VersionRequest, MT_JSON);
  statisticsUpdate(LeakRequest, MT_JSON);
  statisticsUpdate(InvalidRequest, MT_JSON);
  statisticsUpdate(RtSubscribeContextAvailabilityResponse, MT_JSON);
  statisticsUpdate(RtUnsubscribeContextAvailabilityResponse, MT_JSON);
  statisticsUpdate(RtSubscribeResponse, MT_JSON);

  EXPECT_EQ(1, noOfDiscoveries);
  EXPECT_EQ(1, noOfAvailabilitySubscriptionUpdates);
  EXPECT_EQ(1, noOfAvailabilityNotificationsReceived);
  EXPECT_EQ(1, noOfUpdates);
  EXPECT_EQ(1, noOfSubscriptions);
  EXPECT_EQ(1, noOfUnsubscriptions);

  EXPECT_EQ(1, noOfContextEntityAttributes);
  EXPECT_EQ(1, noOfIndividualContextEntity);
  EXPECT_EQ(1, noOfIndividualContextEntityAttribute);
  EXPECT_EQ(1, noOfUpdateContextElement);
  EXPECT_EQ(1, noOfUpdateContextAttribute);
  EXPECT_EQ(1, noOfNgsi10ContextEntityTypesAttributeContainer);
  EXPECT_EQ(1, noOfNgsi10SubscriptionsConvOp);
  EXPECT_EQ(1, noOfVersionRequests);
  EXPECT_EQ(1, noOfLeakRequests);
  EXPECT_EQ(1, noOfInvalidRequests);
  EXPECT_EQ(1, noOfRtSubscribeContextAvailabilityResponse);
  EXPECT_EQ(1, noOfRtUnsubscribeContextAvailabilityResponse);
  EXPECT_EQ(1, noOfRtSubscribeResponse);

  EXPECT_EQ(21, noOfJsonRequests);
}
