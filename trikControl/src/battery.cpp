/* Copyright 2013 Matvey Bryksin, Yurii Litvinov
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

#include "battery.h"

#include "i2cCommunicator.h"

using namespace trikControl;

Battery::Battery(I2cCommunicator &communicator)
	: mCommunicator(communicator)
{
}

float Battery::readVoltage()
{
	QByteArray command(1, '\0');
	command[0] = static_cast<char>(0x26);

	int const parrot = mCommunicator.read(command);

	// TODO: Remove this arcane numbers, or Something may be unexpectedly summoned by them.
	return (static_cast<float>(parrot) / 1023.0) * 3.3 * (7.15 + 2.37) / 2.37;
}
