run: main.o CarRating.o CarRatingService.o ListNode.o
	g++ -o run main.cpp CarRating.o CarRatingService.o ListNode.o

main.o: main.cpp CarRating.hpp CarRatingService.hpp
	g++ -c main.cpp

CarRating.o: CarRating.cpp CarRatingService.hpp
	g++ -c CarRating.cpp

CarRatingService.o: CarRatingService.cpp CarRating.hpp ListNode.hpp
	g++ -c CarRatingService.cpp

ListNode.o: ListNode.cpp CarRating.hpp CarRatingService.cpp
	g++ -c ListNode.cpp
