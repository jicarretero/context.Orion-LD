/*
*
* Copyright 2015 Telefonica Investigacion y Desarrollo, S.A.U
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
* Author: Fermin Galan
*/
#include "orionTypes/EntityTypeVectorResponse.h"
#include "orionld/types/OrionldMimeType.h"
#include "unittests/unittest.h"



/* ****************************************************************************
*
* check
*/
TEST(EntityTypeVectorResponse, check)
{
  utInit();

  EntityType et1("myType");
  EntityType et2("");

  // EntityTypeVectorResponse with a EntityType (in the vector) that will not fail
  EntityTypeVectorResponse etRV1;
  etRV1.entityTypeVector.push_back((&et1));

  // EntityTypeVectorResponse with a EntityType (in the vector) that will fail
  EntityTypeVectorResponse etRV2;
  etRV2.entityTypeVector.push_back((&et2));

  EXPECT_EQ("OK", etRV1.check(API_VERSION_NGSI_V1, false, false, false, ""));

  EXPECT_NE("OK", etRV1.check(API_VERSION_NGSI_V1, false, false, false, "foo"));

  EXPECT_NE("OK", etRV2.check(API_VERSION_NGSI_V1, false, false, false, ""));

  utExit();
}
