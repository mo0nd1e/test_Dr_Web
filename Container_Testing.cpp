#include "pch.h"

#include "../test_Dr_Web/Container.h"
#include "../test_Dr_Web/NotKeyException.h"

TEST(ints, set) {
	Container<int, int> c;
	c.Set(2, 100);
	c.Set(3, 200);
	c.Set(1, 20);
	EXPECT_TRUE(c.IsSet(3));
	EXPECT_TRUE(c.IsSet(2));
	EXPECT_TRUE(c.IsSet(1));
}

TEST(ints, get) {
	Container<int, int> c;
	c.Set(2, 100);
	c.Set(3, 200);
	c.Set(1, 20);
	EXPECT_EQ(c.Get(1), 20);
	EXPECT_EQ(c.Get(3), 200);
	EXPECT_EQ(c.Get(2), 100);
}

TEST(ints, remove) {
	Container<int, int> c;
	c.Set(2, 100);
	c.Set(3, 200);
	c.Set(1, 20);
	c.Remove(1);
	EXPECT_FALSE(c.IsSet(1));
	c.Remove(2);
	EXPECT_FALSE(c.IsSet(2));
	c.Remove(3);
	EXPECT_FALSE(c.IsSet(3));
}

TEST(ints, set_remove) {
	Container<int, int> c;
	c.Set(2, 100);
	c.Set(3, 200);
	c.Set(1, 20);
	c.Remove(1);
	EXPECT_FALSE(c.IsSet(1));
	c.Set(4, 30);
	EXPECT_TRUE(c.IsSet(4));
	c.Remove(2);
	EXPECT_FALSE(c.IsSet(2));
	c.Set(2, 300);
	EXPECT_TRUE(c.IsSet(2));
}

TEST(ints, exceptions) {
	Container<int, int> c;
	c.Set(2, 100);
	c.Set(3, 200);
	c.Set(1, 20);
	c.Remove(2);
	c.Remove(1);
	EXPECT_THROW(c.Remove(2), NotKeyException<int>);
	EXPECT_THROW(c.Remove(1), NotKeyException<int>);
	EXPECT_THROW(c.Remove(5), NotKeyException<int>);
	EXPECT_THROW(c.Get(2), NotKeyException<int>);
	EXPECT_THROW(c.Get(1), NotKeyException<int>);
	EXPECT_THROW(c.Get(5), NotKeyException<int>);
}

TEST(strings, set) {
	Container<std::string, std::string> c;
	c.Set("Sergei", "Esenin");
	c.Set("Alexandr", "Pushkin");
	c.Set("Mikhail", "Lermontov");
	EXPECT_TRUE(c.IsSet("Sergei"));
	EXPECT_TRUE(c.IsSet("Alexandr"));
	EXPECT_TRUE(c.IsSet("Mikhail"));
}

TEST(strings, get) {
	Container<std::string, std::string> c;
	c.Set("Sergei", "Esenin");
	c.Set("Alexandr", "Pushkin");
	c.Set("Mikhail", "Lermontov");
	EXPECT_EQ(c.Get("Sergei"), "Esenin");
	EXPECT_EQ(c.Get("Alexandr"), "Pushkin");
	EXPECT_EQ(c.Get("Mikhail"), "Lermontov");
}

TEST(strings, remove) {
	Container<std::string, std::string> c;
	c.Set("Sergei", "Esenin");
	c.Set("Alexandr", "Pushkin");
	c.Set("Mikhail", "Lermontov");
	c.Remove("Mikhail");
	EXPECT_FALSE(c.IsSet("Mikhail"));
	c.Remove("Sergei");
	EXPECT_FALSE(c.IsSet("Sergei"));
	c.Remove("Alexandr");
	EXPECT_FALSE(c.IsSet("Alexandr"));
}

TEST(strings, set_remove) {
	Container<std::string, std::string> c;
	c.Set("Sergei", "Esenin");
	c.Set("Alexandr", "Pushkin");
	c.Set("Mikhail", "Lermontov");
	c.Remove("Mikhail");
	EXPECT_FALSE(c.IsSet("Mikhail"));
	c.Set("Fedor", "Dostoevsky");
	EXPECT_TRUE(c.IsSet("Fedor"));
	c.Remove("Sergei");
	EXPECT_FALSE(c.IsSet("Sergei"));
	c.Set("Sergei", "Orlov");
	EXPECT_TRUE(c.IsSet("Sergei"));
}

TEST(strings, exceptions) {
	Container<std::string, std::string> c;
	c.Set("Sergei", "Esenin");
	c.Set("Alexandr", "Pushkin");
	c.Set("Mikhail", "Lermontov");
	c.Remove("Sergei");
	c.Remove("Mikhail");
	EXPECT_THROW(c.Remove("Sergei"), NotKeyException<std::string>);
	EXPECT_THROW(c.Remove("Mikhail"), NotKeyException<std::string>);
	EXPECT_THROW(c.Remove("Fedor"), NotKeyException<std::string>);
	EXPECT_THROW(c.Get("Sergei"), NotKeyException<std::string>);
	EXPECT_THROW(c.Get("Mikhail"), NotKeyException<std::string>);
	EXPECT_THROW(c.Get("Fedor"), NotKeyException<std::string>);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}