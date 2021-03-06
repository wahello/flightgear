/*
 * Copyright (C) 2016 Edward d'Auvergne
 *
 * This file is part of the program FlightGear.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "test_props.hxx"


// Set up function for each test.
void SimgearPropsTests::setUp()
{
    // Create a property tree.
    tree = new SGPropertyNode;
}


// Clean up after each test.
void SimgearPropsTests::tearDown()
{
    // Delete the tree (avoiding the memory leak).
    delete tree;
}


// Test property aliasing, to catch possible memory leaks.
void SimgearPropsTests::testAliasLeak()
{
    // Declarations.
    SGPropertyNode *alias;

    // Create a new node.
    tree->getNode("test-node", true);

    // Aliased node.
    alias = tree->getNode("test-alias", true);
    alias->alias("test-node");
}
