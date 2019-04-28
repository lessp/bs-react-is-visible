# React Is Visible for ReasonReact

A small library that lets you know whether a component is visible on screen or not.

Uses the [IntersectionObserver API](https://developer.mozilla.org/en-US/docs/Web/API/IntersectionObserver).

## Installation

```bash
npm install bs-react-is-visible
```

Add `bs-react-is-visible` to `bs-dependencies` in `bsconfig.json`

## Usage

```reasonml
[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible();

  <h1 ref>
    {(isVisible ? "I'm visible!" : "I'm not visibile") |> React.string}
  </h1>;
};
```
