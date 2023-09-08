#!/bin/bash

Scope()
{
  local lcvariable=1
  Gblvariable=2
  echo "lcvariable in function = $lcvariable"
  echo "Gblvariable in function = $Gblvariable"
}

Scope

echo "lcvariable in function = $lcvariable"
echo "Gblvariable in function = $Gblvariable"
