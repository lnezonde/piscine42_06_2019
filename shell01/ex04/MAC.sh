#!/bin/bash
ifconfig | grep ether | tr -d ' '| cut -c7-
