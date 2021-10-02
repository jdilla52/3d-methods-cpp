//
// Created by Jacques Perrault on 10/2/21.
//
#include <catch2/catch.hpp>
#include <iostream>
#include <Eigen/Dense>
SCENARIO("test generate generic reponse", "[utils.cpp]")
{
//auto test = formResponse("succeeded", "i'm a message", "test_func");
//std::string valid =
//        R"({"info":{"functionName":"test_func","info":"i'm some info"},"message":"i'm a message","status":"succeeded"})";
//
//REQUIRE(test == valid);


    using Eigen::MatrixXd;
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
}