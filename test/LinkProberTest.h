/*
 *  Copyright 2021 (c) Microsoft Corporation.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*
 * LinkProberTest.h
 *
 *  Created on: May 12, 2021
 *      Author: Tamer Ahmed
 */

#ifndef LINKPROBERTEST_H_
#define LINKPROBERTEST_H_

#include "gtest/gtest.h"

#include "FakeMuxPort.h"
#include "link_prober/LinkProber.h"

namespace test
{

class LinkProberTest: public ::testing::Test
{
public:
    LinkProberTest();
    virtual ~LinkProberTest() = default;

    void initialize() {mLinkProber.initialize();};
    void initializeSendBuffer() {mLinkProber.initializeSendBuffer();};
    void handleUpdateEthernetFrame() {mLinkProber.handleUpdateEthernetFrame();};
    void handleUpdateSequenceNumber() {mLinkProber.updateIcmpSequenceNo();};
    std::array<uint8_t, MUX_MAX_ICMP_BUFFER_SIZE> getTxBuffer() {return mLinkProber.getTxBuffer();};

    uint16_t getRxSelfSeqNo() {return mLinkProber.mRxSelfSeqNo;};
    uint16_t getRxPeerSeqNo() {return mLinkProber.mRxPeerSeqNo;};

    boost::asio::io_service mIoService;
    common::MuxConfig mMuxConfig;
    std::shared_ptr<FakeDbInterface> mDbInterfacePtr;
    std::string mPortName = "EtherTest01";
    std::string mSmartNicIpAddress = "192.168.1.20";
    uint16_t mServerId = 01;

    FakeMuxPort mFakeMuxPort;
    link_prober::LinkProber mLinkProber;
};

} /* namespace test */

#endif /* LINKPROBERTEST_H_ */
