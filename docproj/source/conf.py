# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'APEx-Sat'
copyright = '2025, Purdue University, Purdue APEx-Sat Team'
author = 'Zuzu Alsuwaidi, Vincent Palmeria, Aahan Mehta, Satvik Agrawal, Vedh Rajesh'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['sphinx.ext.imgmath', 'sphinx.ext.todo', 'breathe']

breathe_projects = {"APEx-Sat": "doxyxml/"}
breathe_default_project = "APEx-Sat"

templates_path = ['_templates']
exclude_patterns = []



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "alabaster"
html_static_path = ['_static']
