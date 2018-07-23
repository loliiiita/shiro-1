#ifndef SHIRO_CHANNEL_MANAGER_HH
#define SHIRO_CHANNEL_MANAGER_HH

#include <unordered_map>

#include "../io/layouts/channel/channel.hh"
#include "../io/osu_writer.hh"
#include "../users/user.hh"

namespace shiro::channels::manager {

    static std::unordered_map<io::layouts::channel, std::vector<std::shared_ptr<users::user>>> channels;

    void init();

    void write_channels(io::osu_writer &buf, std::shared_ptr<shiro::users::user> user);

    // User methods

    void join_channel(uint32_t channel_id, std::shared_ptr<users::user> user);

    void leave_channel(uint32_t channel_id, std::shared_ptr<users::user> user);

    bool in_channel(uint32_t channel_id, const std::shared_ptr<users::user> &user);

    std::vector<std::shared_ptr<users::user>> get_users_in_channel(const std::string &channel_name);

}

#endif //SHIRO_CHANNEL_MANAGER_HH