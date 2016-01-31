/* Copyright 2016 CyberTech Labs Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#include "tcpClientSimulator.h"

using namespace tests::utils;
using namespace trikNetwork;

TcpClientSimulator::TcpClientSimulator(const QString &ip, int port)
	: Connection(Protocol::messageLength, Heartbeat::dontUse)
{
	init(QHostAddress(ip), port);
}

void TcpClientSimulator::processData(const QByteArray &data)
{
	mLatestResponse = QString::fromUtf8(data);
}

QString TcpClientSimulator::latestResponse() const
{
	return mLatestResponse;
}