# [1.2.0](https://github.com/edenreich/console-component/compare/v1.1.0...v1.2.0) (2026-07-26)


### Features

* support positional arguments in command handlers ([#38](https://github.com/edenreich/console-component/issues/38)) ([8164b66](https://github.com/edenreich/console-component/commit/8164b66dacb5f5b0ac0c850fd61e7ad31ee10a06))

# [1.1.0](https://github.com/edenreich/console-component/compare/v1.0.6...v1.1.0) (2026-07-26)


### Bug Fixes

* **ci:** use GitHub App client-id from secret for releaser token ([#49](https://github.com/edenreich/console-component/issues/49)) ([66ac93f](https://github.com/edenreich/console-component/commit/66ac93fa168c141b50d3c25e838d681f70f06dc5))
* **ci:** use GitHub App token for semantic-release instead of GITHUB_TOKEN ([#48](https://github.com/edenreich/console-component/issues/48)) ([669529d](https://github.com/edenreich/console-component/commit/669529df8798cc1a1fde89466ee6fb8dfcceefa6))


### Features

* add OpenTask Agent workflow ([#36](https://github.com/edenreich/console-component/issues/36)) ([96442c8](https://github.com/edenreich/console-component/commit/96442c86f389ac742f871ff42961549ca007f0f0))
* **ci:** add semantic-release process for automated releases ([#39](https://github.com/edenreich/console-component/issues/39)) ([3fc627c](https://github.com/edenreich/console-component/commit/3fc627cdbdec1875a444f293f7e24c1335113505))

# Release Notes

## [Unreleased](https://github.com/edenreich/console-component/compare/v1.0.7...main)

## [v1.0.6 (2020-08-05)](https://github.com/edenreich/console-component/compare/v1.0.5...v1.0.6)

### Added
- Command suggestion - if a command is not found, the cli will try to figure out what command you meant.

### Changed
- None

### Removed
- None

### Fixed
- None

## [v1.0.5 (2020-08-04)](https://github.com/edenreich/console-component/compare/v1.0.4...v1.0.5)

### Added
- Command namespace, all commands are groupped under whatever comes before the colon.

### Changed
- None

### Removed
- None

### Fixed
- None

## [v1.0.4 (2019-10-30)](https://github.com/edenreich/console-component/compare/v1.0.3...v1.0.4)

### Added
- None

### Changed
- Modified the examples to be a bit more clearer

### Removed
- None

### Fixed
- Fixed Input::ask method, now it prints the question and waits for input


## [v1.0.3 (2019-10-21)](https://github.com/edenreich/console-component/compare/v1.0.2...v1.0.3)

### Added
- None

### Changed
- Changed project name from commandline to console-component

### Removed
- None

### Fixed
- None

## [v1.0.2 (2019-08-31)](https://github.com/edenreich/console-component/compare/v1.0.1...v1.0.2)

### Added
- Added formatting output messages, could now achieved by using Output::writeLine(std::string) or Output::write(std::string) same as using fprintf("some string %s and other types %d", "string", 1.5) c function
- Added an overload method that accept also a Console::Types::Color of type enum as first parameter to output the stream in predefined colors (currently supported: colors red, yellow, green)
- Added few tests to cmake using googletest as the testing framework.

### Changed
- None

### Removed
- Removed output::writeLineBreak() method

### Fixed
- None


## [v1.0.1 (2019-06-16)](https://github.com/edenreich/console-component/compare/v1.0.0...v1.0.1)

### Added
- Added support to windows
- Added 3 new methods were added to output interface for outputting errors, warnings and info
- Added options on the command level
- Added one new method was added to input interface for fetching single option

### Changed
- Changed options parsing, it's now a bit more verbose

### Removed
- None

### Fixed
- None


## [v1.0.0 (2019-06-15)](https://github.com/edenreich/console-component/compare/v1.0.0...v1.0.0)

### Added
- Added setters for application name, description, version and usage
- Added a flag to turn on auto print help if needed
- Added global options with aliases
- Added commands functionality
- Added progress bar to output interface

### Changed
- None

### Removed
- None

### Fixed
- None
