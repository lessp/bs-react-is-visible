[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible();

  <div style={ReactDOMRe.Style.make(~height="200vh", ())}>
    <h1 ref>
      {(isVisible ? "I'm visible!" : "I'm not visible!") |> React.string}
    </h1>
  </div>;
};
