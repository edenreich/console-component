# Release Notes

## [Unreleased](https://github.com/edenreich/console-component/compare/v1.0.6...master)

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

