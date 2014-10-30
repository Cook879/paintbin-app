//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Paintbin;

using namespace concurrency;
using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::Phone::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The WebView Application template is documented at http://go.microsoft.com/fwlink/?LinkID=391641

MainPage::MainPage()
{
	InitializeComponent();

	this->NavigationCacheMode = Navigation::NavigationCacheMode::Required;
}

void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(e);	// Unused parameter

	WebViewControl->Navigate(GetHomeUri());

	_backPressedToken = HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs^>(this, &MainPage::MainPage_BackPressed);
}

void MainPage::OnNavigatedFrom(NavigationEventArgs^ e)
{
	(e);	// Unused parameter

	HardwareButtons::BackPressed -= _backPressedToken;
}


void MainPage::Browser_NavigationCompleted(Object^ sender, WebViewNavigationCompletedEventArgs^ e)
{
	(sender);	// Unused parameter
	(e);		// Unused parameter

	//create_task(WebViewControl->InvokeScriptAsync("RemoveScrolling", ref new Vector<String^>()));
#if _DEBUG
	if (!e->IsSuccess)
	{
		OutputDebugStringW(L"Navigation to this page failed, check your internet connection");
	}
#endif
}

/// <summary>
/// Overrides the back button press to navigate in the WebView's back stack instead of the application's.
/// </summary>
void MainPage::MainPage_BackPressed(Object^ sender, BackPressedEventArgs^ e)
{
	(sender);	// Unused parameter
	(e);		// Unused parameter

	if (WebViewControl->CanGoBack)
	{
		WebViewControl->GoBack();
		e->Handled = true;
	}
}

/// <summary>
/// Navigates to the initial home page.
/// </summary>
void MainPage::HomeAppBarButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	(sender);	// Unused parameter
	(e);		// Unused parameter

	WebViewControl->Navigate(GetHomeUri());
}

/// <summary>
/// BLUE!
/// </summary>
void MainPage::BlueAppBarButton_Click(Object^ sender, RoutedEventArgs^ e)
{
	(sender);	// Unused parameter
	(e);		// Unused parameter
	Vector<String^>^ param = ref new Vector<String^>();
	param->Append("colored_sketch?data-color=blue");

	create_task(WebViewControl->InvokeScriptAsync("anchor", param));


}
