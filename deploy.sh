#!/bin/sh

echo "Starting ..."
echo "Be careful! Your machine is now vulnerable."
socat TCP-LISTEN:1337,forever,max-children=-1,reuseaddr,fork EXEC:"./vuln"
