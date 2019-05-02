module Style = {
  let wrapper =
    ReactDOMRe.Style.make(
      ~height="150vh",
      ~display="flex",
      ~flexDirection="column",
      ~alignItems="center",
      ~transition="background-color 1s ease",
      (),
    );

  let box = visible =>
    ReactDOMRe.Style.make(
      ~alignItems="center",
      ~backgroundColor={
        visible ? "hotpink" : "transparent";
      },
      ~color="white",
      ~display="flex",
      ~fontSize="32px",
      ~height="256px",
      ~justifyContent="center",
      ~marginTop="auto",
      ~transition="background-color 1s ease",
      ~width="256px",
      (),
    );
};

[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible();

  <div style=Style.wrapper>
    <h1> {"Scroll down" |> React.string} </h1>
    <div ref style={Style.box(isVisible)}>
      {(isVisible ? "I'm visible!" : "I'm not visible!") |> React.string}
    </div>
  </div>;
};
