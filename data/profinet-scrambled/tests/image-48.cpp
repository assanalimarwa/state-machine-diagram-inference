#include <gtest/gtest.h>
struct Event{};
enum class State
{
  DNS,
  DVR,
  PHP,
  AIK,
  MFA,
  DOS,
};
State handle_event(State const state, Event const & evnet);

TEST(App, DVR)
{
  // CHeck path ['DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, DOS)
{
  // CHeck path ['DVR', 'DOS', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, AIK)
{
  // CHeck path ['DVR', 'DOS', 'AIK', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, PHP)
{
  // CHeck path ['DVR', 'DOS', 'PHP', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, MFA)
{
  // CHeck path ['DVR', 'DOS', 'PHP', 'MFA', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

TEST(App, DNS)
{
  // CHeck path ['DVR', 'DOS', 'PHP', 'MFA', 'DNS', 'DVR']
  Event event;
  auto state = State::DVR;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::PHP);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MFA);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DNS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::DVR);
}

