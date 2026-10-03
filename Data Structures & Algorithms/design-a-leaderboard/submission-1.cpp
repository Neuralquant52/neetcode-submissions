#include <vector>
#include <optional>


class Leaderboard{
public:
        Leaderboard(){

        }

        void addScore(int playerId, int score){
                auto it = std::find_if(data_.begin(), data_.end(), [playerId](const auto& p){
                        return p.first == playerId;
                });

                if (it != data_.end()) it->second = it->second.value_or(0) + score;
                else data_.push_back({playerId, score});
        }

        int top(int K){
                int sum = 0;
                std::sort(data_.begin(), data_.end(), [](const auto& x, const auto& y){
                        return x.second.value_or(0) > y.second.value_or(0);
                });

                for (size_t i{}; i < K; i++){
                    sum += data_[i].second.value_or(0);
                }
                return sum;
        }

        void reset(int playerId){
                auto it = std::find_if(data_.begin(), data_.end(), [playerId](const auto& p){
                        return p.first == playerId;
                });

                if (it != data_.end()) it->second = std::nullopt;
        }

private:
        std::vector<std::pair<unsigned int, std::optional<unsigned int>>> data_;
};
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
