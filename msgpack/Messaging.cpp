#include "Messaging.hpp"
#include "deserialize.hpp"

#ifdef MESSENGER_DEBUG_INCOMING
#include "serialize.hpp"
#endif

namespace msgpack {
	//----------
	bool Messaging::processIncoming(Stream & stream) {
		const bool safely = true;

#ifdef MESSENGER_DEBUG_INCOMING
		msgpack::writeString(stream, "Attempt to read map size");
#endif

		size_t mapSize;
		MSGPACK_SAFELY_RUN(msgpack::readMapSize(stream, mapSize));

		
#ifdef MESSENGER_DEBUG_INCOMING
		msgpack::writeMapSize4(stream, 1);
		msgpack::writeString(stream, "Received map");
		msgpack::writeInt(stream, mapSize);
#endif

		char key[100];
		for(size_t i=0; i<mapSize; i++) {
			size_t stringSize;
			MSGPACK_SAFELY_RUN(msgpack::readString(stream, key, 100, stringSize));

#ifdef MESSENGER_DEBUG_INCOMING
			msgpack::writeMapSize4(stream, 1);
			msgpack::writeString(stream, "Received key");
			msgpack::writeString(stream, key);
#endif

			if (!this->processIncomingByKey(key, stream)) {
				return false;
			}
		}

		return true;
	}
}