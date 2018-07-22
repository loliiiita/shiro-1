#ifndef SHIRO_OSU_PACKET_HH
#define SHIRO_OSU_PACKET_HH

#include "layouts/packets.hh"
#include "osu_buffer.hh"

namespace shiro::io {

    class osu_packet {
    public:
        packet_id id;
        buffer data;

        explicit osu_packet(buffer &data);

        template<typename l>
        l unmarshal() {
            l result;
            result.unmarshal(this->data);

            return result;
        }

    };

}

#endif //SHIRO_OSU_PACKET_HH
