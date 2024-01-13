// Bryant Huynh
// CPSC 121L-01
// 11/27/2023
// 22bhuynh2@csu.fullerton.edu
// @bryqnt
//
// Lab 11-2

#include <memory>
#include <string>

class Train {
 public:
  Train(int passenger_count, int seat_count,
        std::shared_ptr<Train> next_carriage)
      : passenger_count_(passenger_count),
        seat_count_(seat_count),
        next_carriage_(next_carriage) {}

  int GetPassengerCount() const {
    return passenger_count_;
  }
  int GetSeatCount() const {
    return seat_count_;
  }
  std::shared_ptr<Train> GetNextCarriage() const {
    return next_carriage_;
  }
  // ====================== YOUR CODE HERE ======================
  // Define the following recursive member functions, according
  // to the instructions in the README:
  //
  //   1. TotalTrainPassengers
  //   2. MaxCarriagePassengers
  //   3. IsTrainFull
  //   4. AddCarriageToEnd
  // ============================================================
  int TotalTrainPassengers() const {
    if (next_carriage_ == nullptr) {
      return passenger_count_;
    } else {
      return passenger_count_ + next_carriage_->TotalTrainPassengers();
    }
  }
  int MaxCarriagePassengers() const {
    if (next_carriage_ == nullptr) {
      return passenger_count_;
    } else {
      int maxg = next_carriage_->MaxCarriagePassengers();
      int maxt = std::min(passenger_count_, seat_count_);
      return std::max(maxg, maxt);
    }
  }
  bool IsTrainFull() const {
    if (passenger_count_ < seat_count_) {
      return false;
    }
    if (next_carriage_ == nullptr) {
      return true;
    }
    return next_carriage_->IsTrainFull();
  }
  void AddCarriageToEnd(std::shared_ptr<Train> train1) {
    if (next_carriage_ == nullptr) {
      next_carriage_ = train1;
    } else {
      next_carriage_->AddCarriageToEnd(train1);
    }
  }
 private:
  int passenger_count_;
  int seat_count_;
  std::shared_ptr<Train> next_carriage_;
};
