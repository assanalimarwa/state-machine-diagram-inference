#include <gtest/gtest.h>
struct Event{};
enum class State
{
  EXE,
  MAC,
  ERP,
  SDK,
  XSS,
  AIK,
  BIOS,
  WAP,
  LAN,
  GIF,
  SQL,
  CPL,
  VPS,
  JSO,
};
State handle_event(State const state, Event const & evnet);

TEST(App, SDK)
{
  // CHeck path ['SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, AIK)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, MAC)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, BIOS)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, EXE)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'EXE', 'SQL', 'XSS', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, XSS)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'EXE', 'SQL', 'XSS', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

TEST(App, SQL)
{
  // CHeck path ['SDK', 'AIK', 'MAC', 'EXE', 'SQL', 'XSS', 'MAC', 'BIOS', 'SDK']
  Event event;
  auto state = State::SDK;
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::AIK);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::EXE);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SQL);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::XSS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::MAC);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::BIOS);
  // TODO: fill event appropriately
  state = handle_event(state, event);
  ASSERT_EQ(state, State::SDK);
}

